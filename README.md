# spacebridgehabpcb

HAB PCB Tracker with cutdown, GPS, enviromental monitoring, LoRa telemetry

Created by Lucy Moglia <eigenlucy@proton.me>

## Atopile usage 101
See atopile docs for detailed guides on usage: https://docs.atopile.io/atopile/introduction

### Linux Install (should work with Ubuntu, Debian, Arch, and NixOS)
1: Install [uv](https://github.com/astral-sh/uv)

2: Install kicad with your preferred package manager (apt for debian, pacman for arch, etc)

3: Install atopile as a tool with uv. As of writing this, you should be using python 3.13.2
```bash
$ uv tool install atopile
```

3.1: (alternative install, my preferred method, easier to debug and manage versions):

3.2: clone the main [atopile repo](https://github.com/atopile/atopile)

3.3: ```$ cd atopile```, ```$ rm uv.lock```

3.4: ```$ uv sync --dev```

3.5: ```$ uv build </ul>```

3.6: ```$ uv tool install atopile-0.3.XX-cp313-cp313-linux-_x86_64.whl```

3.7: Add the uv tools binary directory to you path with something like ```$ fish_add_path /home/user/.local/share/uv/tools/atopile/```

4: Check your version with ```$ ato --version```

5: configure the atopile plugin
```bash
$ ato configure
```

### Mac Install
1: Install [Homebrew](https://brew.sh/)

2: Install [kicad 9](https://formulae.brew.sh/cask/kicad) 

3: install atopile with Homebrew
```bash
$ brew install atopile/tap/atopile
```

4: configure the atopile plugin
```bash
$ ato configure
```

### Project Sturcture
| file          | kicad_pcb path | Description  |
| ------------- |:-------------: | ------------:|
| ~/mainboard.ato | ~/layouts/default/default.kicad_pcb | the final pcb incorporating all submodules |
| ~/micromppt.ato | ~/micromppt/elec/layout/default/micromppt.kicad_pcb | 5W MPPT battery charger with embedded set point adjustment algorithm |
| ~/particle_counter.ato | ~/layouts/particle-counter/particle-counter.kicad_pcb | alpha particle detector based on CERN open source hardware kit |
| ~/cutoff.ato | ~/layouts/cutoff/cutoff.kicad_pcb | Balloon cutoff circuit, discharges a lithium hybrid supercapacitor through nichrome wire wrapped around the rope tying the payload to the balloon |
