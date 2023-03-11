# packr

Packr is a concept (that is, work in progress) "hybrid" package manager for GNU/Linux. This
means it can be used to both install packages by compiling them on the user's
system, and install precompiled binaries created by other users like yourself,
both through local packages and through repositories.

## Planned features (TODO)

- Installation and removal of software (basic stuff)
- Repository support (Using Git, anything else is dumb)
- Portage-like USE flags
- Ability to create binary packages from source packages which can
then be shared and installed at any time (as long as the USE flags match)
