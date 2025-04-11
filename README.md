# spacebridgehabpcb

HAB PCB Tracker with cutdown, GPS, enviromental monitoring, LoRa telemetry

Created by Lucy Moglia <eigenlucy@proton.me>

# Project Structure
| title | file | kicad_pcb path | description  |
| :---------: | :----------------: |:-----------------: | :---------------------------------:|
| mainboard | ~/mainboard.ato | ~/layouts/default/default.kicad_pcb | the final pcb incorporating all submodules |
| micromppt | ~/micromppt/elec/src/micromppt.ato | ~/micromppt/elec/layout/default/micromppt.kicad_pcb | 5W MPPT battery charger with embedded set point adjustment algorithm |
| particle counter | ~/particle_counter.ato | ~/layouts/particle-counter/particle-counter.kicad_pcb | alpha particle detector based on CERN open source hardware kit |
| cutoff mechanism | ~/cutoff.ato | ~/layouts/cutoff/cutoff.kicad_pcb | Balloon cutoff circuit, discharges a lithium hybrid supercapacitor through nichrome wire wrapped around the rope tying the payload to the balloon |
| bq24045dsqr BMS | ~/bq24045dsqr/elec/src/bq24045dsqr.ato |  ~/bq24045dsqr/elec/layout/default/bq24045dsqr.kicad_pcb | 5V 1A single cell lipo/lion charger + BMS |
| tps63020dsjr 5V boost-buck | ~/.ato/modules/tps63020dsjr/elec/src/tps63020dsjr.ato | ~/.ato/modules/tps63020dsjr/elec/layout/tps63020dsjr.kicad_pcb | 1.8V-5.5V In/Out 4A boost-buck converter. Supplies 5V from Vbat |

![Block Diagram](https://github.com/eigenlucy/spacebridgehabpcb/blob/main/references/BlockDiagram.png)

# Atopile usage 101
See [atopile docs](https://docs.atopile.io/atopile/introduction) for detailed guides on usage. Install instructions below

## Building the project
### 1: Clone the required submodules
```$ git submodule update --init --recursive```
### 2: Build the project to select components based on JLCPCB availability and load them into the kicad PCB
``` $ ato build -t all```
### 3: Complete/review the layout with Kicad Standalone PCB editor
### 4: Gerbers/PCBA files are generated through an Actions run on a commit and placed in the build artifacts folder

## Linux Install (should work with Ubuntu, Debian, Arch, and NixOS)
### 1: Install [uv](https://github.com/astral-sh/uv)
### 2: Install kicad with your preferred package manager (apt for debian, pacman for arch, etc)
### 3: Install atopile as a tool with uv. As of writing this, you should be using python 3.13.2 
```$ uv tool install atopile```
#### 3.1: (alternative install, my preferred method, easier to debug and manage versions):
#### 3.2: clone the main [atopile repo](https://github.com/atopile/atopile)
#### 3.3: remove the uv lock file
```$ rm uv.lock```
#### 3.4: sync repo to dev release
```$ uv sync --dev```
#### 3.5: compile atopile
```$ uv build```
#### 3.6: install the binary
```$ uv tool install atopile-0.3.XX-cp313-cp313-linux-_x86_64.whl```
#### 3.7: Add the uv tools binary directory to your PATH (command depends on your shell, eg with fish)
```$ fish_add_path /home/user/.local/share/uv/tools/atopile/```
### 4: Check your version with 
```$ ato --version```
### 5: configure the atopile plugin 
```$ ato configure```

## Mac Install
### 1: Install [Homebrew](https://brew.sh/)
### 2: Install [kicad 9](https://formulae.brew.sh/cask/kicad)
### 3: install atopile with Homebrew 
```$ brew install atopile/tap/atopile```
### 4: configure the atopile plugin 
```$ ato configure```

## Visual Studio Code/Cursor Extension Install
Install the [atopile extension](https://marketplace.visualstudio.com/items?itemName=atopile.atopile) into Cursor or VSC
