#!/bin/sh
USER="packr"
GROUP="packr"

create_basedir() {
    mkdir -p /etc/packr
    touch /etc/packr/packr.conf
    [ -f "doc/default/packr.conf" ] && cp "doc/default/packr.conf" "/etc/packr/packr.conf"
}

perm_basedir() {
    chmod -R 0755 "/etc/packr"
    chown -R ${USER}:${GROUP} "/etc/packr"
}

mk_usr() {
    groupadd -rf "${GROUP}"
    useradd -g "${GROUP}" -s "/bin/sh" -c "The user account for packr" -r "${USER}"
}

main() {
    [ "$(id -u)" != "0" ] && printf "This script must run as superuser.\n" && exit 1

    create_basedir "$@"
    mk_usr "$@"
    perm_basedir "$@"
}

main "$@"
