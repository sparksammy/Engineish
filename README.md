# CallieNaps_Blue
"The best way to hax is to think simple, yet outside the box at the same time." --Samuel Lord

Note: Made for macOS, and made for building on Ubuntu WSL. ***This may or may not work in it's current state, or future states, as I don't have a Mac to test it with.***
Note 2: I ***do not*** own the files in Lua/ and ***I didn't*** make the files in calamari-ios-mods/ myself, hence the name.

## How does it work?
It uses a simple (semi-custom?) LUA VM to put code into ROBLOX's engine that allows you to execute pre-built commands once the .SO is injected.

## Dependencies?
sudo apt install -y liblua5.1-0-dev

## Could this work in iOS?
Maybe, if someone were to fork it, yes. It *is* heavily inspired by Calamari (The ROBLOX scripting tool, not the squid.) and Custom Lua VM (but just without some of the the custom), so maybe.

## What about Windows 10?
If someone forked it, replaced the bypass code with this: https://github.com/sparksammy/ReturnCheck and compiled/linked it in Visual Studio as a DLL, maybe.
