 
Minetest++

A game built off of the best free and open source Minecraft clone, Minetest-C55.

Copyright (c) 2010-2012 Perttu Ahola celeron55@gmail.com and ther contributors (see source file comments and the version control log)

This contains 2 different game modes, Minetest and Minimal. Game mode Minimal is just a test and will be taken out soon. Game mode Minetest has all the cool features.
Further documentation

    Website: http://www.minetest.net
    Wiki: http://wiki.minetest.com
    Forum: http://www.minetest.net/forum

This game is in alpha!

    Don't expect it to work as well as a finished game will.
    Please tell me about any bugs you come across. Just look in your debug.txt file. (/minetest/bin/debug.txt)
    But other then that, have fun and expect new features :)

Default Controls

    WASD: Move
    Space: Jump
    E:
        While walking: Run (need the fast privelage)
        While flying: Go down
    Shift: Sneak
    Q: Drop item
    R: Open inventory
    Mouse: Turn/look
    C: Toggle fly (need fly privelage)
    X: toggle fast (need fast Privelage)
    Settable in the configuration file, see the section below.

Compiling:
GNU/Linux
Install dependencies.

Here's an example for Debian/Ubuntu: sudo apt-get install build-essential libirrlicht-dev cmake libbz2-dev libpng12-dev libjpeg8-dev libxxf86vm-dev libgl1-mesa-dev libsqlite3-dev libogg-dev libvorbis-dev libopenal-dev libcurl3
Download source:
Method 1: Download tarball

wget https://github.com/jordan4ibanez/minetest/tarball/master -O master.tar.gz
tar xf master.tar.gz
cd jordan4ibanez-minetest-*

Method 2: Clone from git

git clone git://github.com/jordan4ibanez/minetest.git minetestpp
cd minetestpp

Build
Method 1: Build a version that runs directly from the source directory

cmake . -DRUN_IN_PLACE=1
make -j2

Method 2: Build a version that can be installed system-wide

mkdir build && cd build
cmake ..
make
sudo make install

    Use cmake . -LH to see all CMake options and their current state
    If you want to install it system-wide (or are making a distribution package), you will want to use -DRUN_IN_PLACE=0
    You can build a bare server or a bare client by specifying -DBUILD_CLIENT=0 or -DBUILD_SERVER=0
    You can select between Release and Debug build by -DCMAKE_BUILD_TYPE=
        Debug build is slower, but gives much more useful output in a debugger

Windows :

    This section is outdated. In addition to what is described here:
        In addition to minetest, you need to download minetest_game.
        If you wish to have sound support, you need libogg, libvorbis and libopenal

    You need:
        CMake: http://www.cmake.org/cmake/resources/software.html
        MinGW or Visual Studio http://www.mingw.org/ http://msdn.microsoft.com/en-us/vstudio/default
        Irrlicht SDK 1.7: http://irrlicht.sourceforge.net/downloads.html
        Zlib headers (zlib125.zip) http://www.winimage.com/zLibDll/index.html
        Zlib library (zlibwapi.lib and zlibwapi.dll from zlib125dll.zip): http://www.winimage.com/zLibDll/index.html
		Freetype library
        Optional: gettext bibrary and tools: http://gnuwin32.sourceforge.net/downlinks/gettext.php
            This is used for other UI languages. Feel free to leave it out.
        And, of course, Minetest-c55: http://c55.me/minetest/download

    Steps:
        Select a directory called DIR hereafter in which you will operate.
        Make sure you have CMake and a compiler installed.
        Download all the other stuff to DIR and extract them into there. ("extract here", not "extract to packagename/") NOTE: zlib125dll.zip needs to be extracted into zlib125dll
        All those packages contain a nice base directory in them, which should end up being the direct subdirectories of DIR.
        You will end up with a directory structure like this:
        DIR
            zlib-1.2.5.tar.gz
            zlib125dll.zip
            irrlicht-1.7.1.zip
            110214175330.zip (or whatever, this is the minetest source)
            zlib-1.2.5
                zlib.h
                win32 ...
            zlib125dll
                readme.txt
                dll32 ...
            irrlicht-1.7.1
                lib
                include ...
            gettext (optional) +bin +include +lib
            minetest
                src
                doc
                CMakeLists.txt
        Start up the CMake GUI
        Select "Browse Source..." and select DIR/minetest
        Now, if using MSVC:
            Select "Browse Build..." and select DIR/minetest-build
        Else if using MinGW:
            Select "Browse Build..." and select DIR/minetest
        Select "Configure"
        Select your compiler
        It will warn about missing stuff, ignore that at this point. (later don't)
        Make sure the configuration is as follows (note that the versions may differ for you):

    -----------------
    BUILD_CLIENT             [X]
    BUILD_SERVER             [ ]
    CMAKE_BUILD_TYPE         Release
    CMAKE_INSTALL_PREFIX     DIR/minetest-install
    IRRLICHT_SOURCE_DIR      DIR/irrlicht-1.7.1
    RUN_IN_PLACE             [X]
    WARN_ALL                 [ ]
    ZLIB_DLL                 DIR/zlib125dll/dll32/zlibwapi.dll
    ZLIB_INCLUDE_DIR         DIR/zlib-1.2.5
    ZLIB_LIBRARIES           DIR/zlib125dll/dll32/zlibwapi.lib
    GETTEXT_BIN_DIR          DIR/gettext/bin
    GETTEXT_INCLUDE_DIR      DIR/gettext/include
    GETTEXT_LIBRARIES        DIR/gettext/lib/intl.lib
    GETTEXT_MSGFMT           DIR/gettext/bin/msgfmt
    -----------------

    Hit "Configure"
    Hit "Configure" once again 8)
    If something is still coloured red, you have a problem.
    Hit "Generate" If using MSVC:
        Open the generated minetest.sln
        The project defaults to the "Debug" configuration. Make very sure to select "Release", unless you want to debug some stuff (it's slower and might not even work at all)
        Build the ALL_BUILD project
        Build the INSTALL project
        You should now have a working game with the executable in DIR/minetest-install/bin/minetest.exe
        Additionally you may create a zip package by building the PACKAGE project. If using MinGW:
        Using the command line, browse to the build directory and run 'make' (or mingw32-make or whatever it happens to be)
        You may need to copy some of the downloaded DLLs into bin/, see what running the produced executable tells you it doesn't have.
        You should now have a working game with the executable in DIR/minetest/bin/minetest.exe

This can be automated with a batch script like this

set sourcedir=%CD%
set installpath="C:\tmp\minetest_install"
set irrlichtpath="C:\tmp\irrlicht-1.7.2"

set builddir=%sourcedir%\bvc10
mkdir %builddir%
pushd %builddir%
cmake %sourcedir% -G "Visual Studio 10" -DIRRLICHT_SOURCE_DIR=%irrlichtpath% -DRUN_IN_PLACE=1 -DCMAKE_INSTALL_PREFIX=%installpath%
if %errorlevel% neq 0 goto fail
"C:\WINDOWS\Microsoft.NET\Framework\v4.0.30319\MSBuild.exe" ALL_BUILD.vcxproj /p:Configuration=Release
if %errorlevel% neq 0 goto fail
"C:\WINDOWS\Microsoft.NET\Framework\v4.0.30319\MSBuild.exe" INSTALL.vcxproj /p:Configuration=Release
if %errorlevel% neq 0 goto fail
"C:\WINDOWS\Microsoft.NET\Framework\v4.0.30319\MSBuild.exe" PACKAGE.vcxproj /p:Configuration=Release
if %errorlevel% neq 0 goto fail
popd
echo Finished.
exit /b 0

:fail
popd
echo Failed.
exit /b 1

License of Minetest-c55 textures and sounds

This applies to textures and sounds contained in the main Minetest distribution.

Attribution-ShareAlike 3.0 Unported (CC BY-SA 3.0)
http://creativecommons.org/licenses/by-sa/3.0/
License of Minetest-c55 source code

Minetest-c55 Copyright (C) 2010-2011 celeron55, Perttu Ahola celeron55@gmail.com

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
Irrlicht

This program uses the Irrlicht Engine. http://irrlicht.sourceforge.net/

The Irrlicht Engine License

Copyright © 2002-2005 Nikolaus Gebhardt

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

    The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
    Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
    This notice may not be removed or altered from any source distribution.

JThread

This program uses the JThread library. License for JThread follows:

Copyright (c) 2000-2006 Jori Liesenborgs (jori.liesenborgs@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
Lua

Lua is licensed under the terms of the MIT license reproduced below. This means that Lua is free software and can be used for both academic and commercial purposes at absolutely no cost.

For details and rationale, see http://www.lua.org/license.html .

Copyright (C) 1994-2008 Lua.org, PUC-Rio.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
Fonts

DejaVu Sans Mono:

Fonts are (c) Bitstream (see below). DejaVu changes are in public domain. Glyphs imported from Arev fonts are (c) Tavmjong Bah (see below)

Bitstream Vera Fonts Copyright:

Copyright (c) 2003 by Bitstream, Inc. All Rights Reserved. Bitstream Vera is a trademark of Bitstream, Inc.

Arev Fonts Copyright:

Copyright (c) 2006 by Tavmjong Bah. All Rights Reserved.

Press Start 2P Font by:

codeman38 http://www.zone38.net/font/

FreeType 2:

This program uses the FreeType library.

Copyright (c) 2011 The FreeType Project (www.freetype.org).
FreeType is licensed under the GNU General Public License, version 2 or later.

(Actually, FreeType is dual-licensed, the other license being the BSD-like
FreeType License with advertisement clause.)


ustring and CGUITTFont:

This program uses the ustring and CGUITTFont classes.
http://irrlicht.sourceforge.net/forum/viewtopic.php?f=6&t=37296

Basic Unicode string class for Irrlicht.
Copyright (c) 2009-2011 John Norman

CGUITTFont FreeType class for Irrlicht
Copyright (c) 2009-2010 John Norman

License for ustring and CGUITTFont:

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any
damages arising from the use of this software.

Permission is granted to anyone to use this software for any
purpose, including commercial applications, and to alter it and
redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you
   must not claim that you wrote the original software. If you use
   this software in a product, an acknowledgment in the product
   documentation would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and
   must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any source
   distribution.

The original version of this class can be located at:
http://irrlicht.suckerfreegames.com/

John Norman
john@suckerfreegames.com
