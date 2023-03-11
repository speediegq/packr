# packr

Packr is a (work in progress) "hybrid" package manager for GNU/Linux. This
means it can be used to both install packages by compiling them on the user's
system, and install precompiled binaries created by other users like yourself,
both through local packages and through repositories.

## Planned features (TODO)

- Installation and removal of software (basic stuff)
- Repository support (Using Git, anything else is dumb)
- Portage-like USE flags
- Ability to create binary packages from source packages which can
then be shared and installed at any time (as long as the USE flags match)

## Design goals

- Don't be in the way

The user of the package manager, and all packages compatible with packr
should simply be installed as per the instructions. Other package managers
like Portage put arbitrary restrictions in your face which makes it difficult
to write packages for some projects.

Making packages should be as simple, and quick as possible. This allows
packages to be created faster, and as a result packr will be more useful.

- Follow the UNIX philosophy.

Follow the UNIX philosophy. Use plain text as much as
possible, because that's a universal format that any program
may interact with.

Sign packages using PGP keys instead of some stupid weird format.

- The existing directory structure is fine, don't fix it.

Don't put binaries in some stupid new directory. Package managers
like Nix (on NixOS) put binaries wherever they want and that's dumb.

- Shell based packaging format.

Packages should be written in shell, because shell is something all GNU/Linux
users are familiar with.

- Be minimal, and written in mostly C.

Packr should be minimal, and it should be written in mostly C. Write certain
things in shell, such as reading the packaging format, because the packaging
format is shell based.

- Do not bow down to normies.

Packr should **not** ever bow down to normies. Packr is written with
experienced users in mind who are willing to learn GNU/Linux and UNIX-like software.

A lot of software these days are written with people who are coming from
operating systems like Windows in mind. This makes the software much, much
worse, unbearably so.

By adopting this "anti-normie" stance, the software will be much better. That said,
we will provide support to good questions asked, and we will support normies
who are actually willing to learn *our* software.

- Work on any GNU/Linux distribution

While compatibility with other operating systems is not in our interest just
yet, compatibility with any GNU/Linux distribution certainly is.

I understand that it is hard to start a new distribution, and most
distributions fail. Therefore, while Packr doesn't have many packages, it is
a good idea to allow usage on other distributions, which will allow the use
of another package manager to fill the void.

Once there are enough packages in the repositories, a distribution using only
Packr may be created. One of the ways to get more packages in the repos
is to make the creation of packages as easy and quick as possible.

- Clearly notify users of antifeatures

Another area that many GNU/Linux distributions fail at is properly notifying
users of proprietary licenses and antifeatures such as connecting to a
server without the users's concent.

Free software programs like the Kitty terminal have been shown to connect
to servers in the past without notifying the users.

Official repositories should also only contain free (as in freedom)
software. Finally, work *against* nonfree programs by licensing
Packr software under GPLv3 when possible.
