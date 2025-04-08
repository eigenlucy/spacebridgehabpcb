# spacebridgehabpcb

HAB PCB Tracker with cutdown, GPS, enviromental monitoring, LoRa telemetry

Created by Lucy Moglia <eigenlucy@proton.me>

## Atopile usage 101
See atopile docs for detailed guides on usage: https://docs.atopile.io/atopile/introduction

### Linux Install (should work with Ubuntu, Debian, Arch, and NixOS)
1: Install [uv](https://github.com/astral-sh/uv)
2: Install kicad with your preferred package manager (apt for debian, pacman for arch, etc)
3: Install atopile as a tool with uv. As of writing this, you should be using python 3.13.2
```
$ uv tool install atopile
```
3.1 (alternative install, my preferred method, easier to debug and manage versions):
<ul>clone the main [atopile repo](https://github.com/atopile/atopile)</ul>
<ul>```$ cd atopile```, ```$ rm uv.lock```</ul>
<ul>```$ uv sync --dev```</ul>
<ul>```uv build```</ul>
<ul>```uv tool install atopile-0.3.XX-cp313-cp313-linux-_x86_64.whl</ul>
<ul>add the uv tools binary directory to you path with something like ```$ fish_add_path /home/user/.local/share/uv/tools/atopile/```</ul>
4: Check your version with ```$ ato --version```
4: configure the atopile plugin
```
$ ato configure
```

### Mac Install
1: Install [Homebrew](https://brew.sh/)
2: Install [kicad 9](https://formulae.brew.sh/cask/kicad) 
3: install atopile with Homebrew
```
$ brew install atopile/tap/atopile
```
4: configure the atopile plugin
```
$ ato configure
```

