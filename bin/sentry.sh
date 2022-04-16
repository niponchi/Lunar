#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
if [ -f $DIR/.env.sh ]; then
    source $DIR/.env.sh
fi
if [[ "$DISABLE_SENTRY" == 1 ]]; then
    exit 0
fi

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
if [ -f $DIR/.env.sh ]; then
    source $DIR/.env.sh
fi

if ! which sentry-cli >/dev/null; then
    npm i -g @sentry/cli
fi

export SENTRY_ORG=alin-panaitiu
export SENTRY_PROJECT=lunar
sentry-cli upload-dif --include-sources -o alin-panaitiu -p lunar --wait -- "$DWARF_DSYM_FOLDER_PATH" 2>&1 >> /tmp/lunar-buildscript.log &

# Create a release
ERROR=$(sentry-cli releases -o "$SENTRY_ORG" new -p $SENTRY_PROJECT v$VERSION 2>&1 >/dev/null)
if [ ! $? -eq 0 ]; then
    echo "warning: sentry-cli - $ERROR"
fi

# Associate commits with the release
ERROR=$(sentry-cli releases -o "$SENTRY_ORG" set-commits --auto v$VERSION 2>&1 >/dev/null)
if [ ! $? -eq 0 ]; then
    echo "warning: sentry-cli - $ERROR"
fi

# Finalize release
ERROR=$(sentry-cli releases -o "$SENTRY_ORG" finalize v$VERSION 2>&1 >/dev/null)
if [ ! $? -eq 0 ]; then
    echo "warning: sentry-cli - $ERROR"
fi
