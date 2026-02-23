<h1 align="center">sandy 🏖️</h1>
<p align="center">Run macOS programs in a sandbox.</p>

## Description
`sandy` is a sandbox orchestration tool for macOS.
It acts as an abstraction layer around macOS kernel 
userspace APIs (`sandbox`, `sandbox-exec`, `sandbox-init`, `sandboxd`). It
wraps around all the different sandbox tools to provide a single
interface for creating, managing, and running programs within a sandbox.

## Usage
Simply run `sandy` followed by the command you wish to run inside a
sandbox.

Sandbox configurations are declared through **profiles**. `sandy` comes with some default
profiles you can pick from or you can create your own. By default, `sandy` stores all profiles inside `~/.config/sandy/profiles`. Alternatively, you can pass a file path as an argument to specify which profile you'd like to use.

Sandbox policies are usually written in a Scheme dialect called SBPL that
comes with it's own set of benefits and tradeoffs. Instead, `sandy`
profiles are written in YAML which are then translated to SBPL when `sandy` is
ran. This makes for an easier to read configuration file while still being
extensible.

## API
`sandy` also includes an API for running processes within a sandbox inside your own programs.

## Roadmap
In the future, `sandy` aims to improve the sandbox tooling experience
compared to what is currently provided by the sandbox userspace APIs.
This includes real-time violation logging, human-readable denial
messages, a trace mode, and structured logs.
Potential other features include:
- A dry-run mode
- Learn mode (observe all syscalls/files touched)
- Least-privilege profile generator
- Policy regression testing
- Controlled network allowlists
- CPU/Memory resource limits
