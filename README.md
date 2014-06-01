#Known Hosts

A simple cli known hosts manager

## Installation

### OS X (Using homebrew)

```
brew update
brew install known_hosts
```

### From source

Clone this repo and run

```
make
sudo make install
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
