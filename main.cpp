#include <opencv2/opencv.hpp>


static bool setColorfull = true;

void createCharsForImage(const cv::Mat gray, const cv::Mat color)
{
    std::string buffer;

    buffer.reserve(gray.cols * (gray.rows + 1) * 20);

    for (unsigned int y = 0; y < gray.rows; y++)
    {
        for (unsigned int x = 0; x < gray.cols; x++)
        {
            unsigned char luminance = gray.data[y * gray.cols + x];
            unsigned char b = color.at<cv::Vec3b>(y, x)[0];
            unsigned char g = color.at<cv::Vec3b>(y, x)[1];
            unsigned char r = color.at<cv::Vec3b>(y, x)[2];

            if (setColorfull)
            {
                buffer += "\033[0m";
                buffer += "\033[38;2;" + std::to_string((int)r) + ";" + std::to_string((int)g) + ";" + std::to_string((int)b) + "m";
            }
            else
            {
                buffer += "\033[0m";
            }

            if (luminance < 29) buffer += " ";
            else if (luminance < 58) buffer += ".";
            else if (luminance < 87) buffer += ",";
            else if (luminance < 116) buffer += "-";
            else if (luminance < 145) buffer += "~";
            else if (luminance < 174) buffer += "*";
            else if (luminance < 203) buffer += "1";
            else if (luminance < 232) buffer += "9";
            else if (luminance < 255) buffer += "W";
            else buffer += "@";
        }
        buffer += "\n";
    }

    std::system("clear");
    std::cout << buffer << std::flush;
}


int main()
{
  cv::VideoCapture cap(0);

  if (!cap.isOpened()) {
      std::cerr << "Ошибка: не удалось открыть камеру" << std::endl;
      return -1;
  }

  while(1)
  {
      cv::Mat frame, gray;

      cap >> frame;

      if (frame.empty()) {
          std::cerr << "Ошибка: пустой кадр" << std::endl;
          break;
      }

      cv::Mat resized;

      int new_width = frame.cols / 4;
      int new_height = frame.rows / 8;

      cv::resize(frame, resized, cv::Size(new_width, new_height));

      cv::cvtColor(resized, gray, cv::COLOR_BGR2GRAY);

      createCharsForImage(gray, resized);

      cv::imshow("frame", resized);
      int key = cv::waitKey(30) & 0xFF;
      if (key == 'c' || key == 'C')
      {
        setColorfull = !setColorfull;
      }
  }

  cap.release();
  cv::destroyAllWindows();

  return 0;
}
