#!/bin/bash

firesim launchrunfarm -c workloads/spec17-speed.ini
firesim infrasetup -c workloads/spec17-speed.ini
firesim runworkload -c workloads/spec17-speed.ini
firesim terminaterunfarm -c workloads/spec17-speed.ini
