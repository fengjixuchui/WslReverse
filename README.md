# WSL_Reverse

Reveal hidden COM interface between WSL and Lxss Manager Service. Heavily inspired by kernel guru **Alex Ionescu's project [lxss](https://github.com/ionescu007/lxss)**. This project is just a concept, not a fully developed program and should be used for testing purposes. 

## How to build

Clone this repository. Open the solution (.sln) or project (.vcxproj) file in Visual Studio and build it. ALternatively, run Visual Studio developer command prompt, go to the cloned folder and run this command: `msbuild.exe /p:Configuration=Release`. You can also build with mingw-w64 toolchain. Go to the folder in terminal run `mingw32-make` command for mingw-w64/msys2/cygwin. Some values are not defined in mingw-w64 toolchain. It will be updated soon.

## Usage

This project only shows the hidden COM methods which may change in future Windows version. The current COM vtable, used in this project, is according with 19H1 Insider version. Use only **Windows 10 Insider Preview Build 18234** or higher. Here are the options of WslReverse: 

```
Usage: WslReverse.exe [-] [option] [argument]
Options:
    -d, --get-id       [distribution name]      Get distribution ID.
    -G, --get-default                           Get default distribution ID.
    -g, --get-config   [distribution name]      Get distribution configuration.
    -h, --help                                  Show list of options.
    -i, --install      [distribution name]      Install distribution (only as administrator).
    -r, --run          [distribution name]      run a Linux binary.
    -S, --set-default  [distribution name]      Set default distribution.
    -s, --set-config   [distribution name]      Set configuration for distribution.
    -t, --terminate    [distribution name]      Terminate running distribution.
    -u, --uninstall    [distribution name]      Uninstall distribution.
```

Check out the Others folder to unleashes the hidden beast. Here are the list of files in Other folders: 

* [Lxss_Service.REG](Others/Lxss_Service.REG): Enables Adss Bus, Force case sensitivity in DRVFS, Enable default flag and more fun stuffs. 
* [ExtractResource.c](Others/ExtractResource.c): Extract `init` and `bsdtar` from LxssManager.dll file. From Windows 10 insider build 18242, this doesn't work because `init` and `bsdtar` provided separately. 
* [SuspendUpgrade.c](Others/SuspendUpgrade.c): Suspend upgrade with `wslconfig /upgrade` command. 

## License 

This project is licensed under GNU Public License v3 or higher. You are free to study, modify or distribute the source code. 

```
WslReverse -- (c) Copyright 2018 Biswapriyo Nath

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
```
