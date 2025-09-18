```
╔═══════════════════════════════════════════════════════════════════════════════════════════╗
║                                                                                           ║
║  █████╗ ███╗   ██╗███████╗██╗ ██████╗  ██████╗ █████╗ ███╗   ███╗███████╗██████╗  █████╗  ║
║ ██╔══██╗████╗  ██║██╔════╝██║██╔═══██╗██╔════╝██╔══██╗████╗ ████║██╔════╝██╔══██╗██╔══██╗ ║
║ ███████║██╔██╗ ██║███████╗██║██║██╗██║██║     ███████║██╔████╔██║█████╗  ██████╔╝███████║ ║
║ ██╔══██║██║╚██╗██║╚════██║██║██║██║██║██║     ██╔══██║██║╚██╔╝██║██╔══╝  ██╔══██╗██╔══██║ ║
║ ██║  ██║██║ ╚████║███████║██║╚█║████╔╝╚██████╗██║  ██║██║ ╚═╝ ██║███████╗██║  ██║██║  ██║ ║
║ ╚═╝  ╚═╝╚═╝  ╚═══╝╚══════╝╚═╝ ╚╝╚═══╝  ╚═════╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝ ║
║                                                                                           ║
╚═══════════════════════════════════════════════════════════════════════════════════════════╝
```
# IT'S ONLY FOR LINUX
## Quick start:
```
sudo apt update
sudo apt install kitty
kitty
```
### On kitty:
```
cd ~
git clone https://github.com/kirilllapi/ANSI-Camera.git
cd ANSI@Camera/
./run.sh
```

To change the mode (with color/without color) use the keyboard -> press "```c```" (Aim the camera at the window, not at the terminal).

If you want to clone into another directory, replace command in ```run.sh```:
```
nano run.sh
export LD_LIBRARY_PATH=$HOME/YOUR_DIRECTORY/ANSI@Camera/opencv_pc/lib:$LD_LIBRARY_PATH 
```
