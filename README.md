#Known Hosts

A simple cli ssh **known_hosts** manager

## Installation

### OS X (Using homebrew)

```
brew update
brew install known_hosts
```

### From source

### Requirments

You must have cmake installed.

### Install

Clone this repo and run

```
mkdir build
cd build
cmake ..
make && make install
```

## Usage

```
usage: known_hosts command [host]
  commands:
    ls      - List all known hosts
    rm      - Remove a host [requires host]
    version - Display current version
    help    - Show this message
```