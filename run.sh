#!/bin/bash

make
likwid-perfctr -C 0-3 -g "FLOPS_DP" -m ./interpola $1 < pontos.in > resultado.out
