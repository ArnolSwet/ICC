#!/bin/bash
./lab2-1mf coefs 0.75 1.25 100 > sortf3
./lab2-1mf coefs 0.75 1.25 1000 > sortf4
./lab2-1mf coefs 0.75 1.25 10000 > sortf5
./lab2-1md coefs 0.75 1.25 100 > sortd3
./lab2-1md coefs 0.75 1.25 1000 > sortd4
./lab2-1md coefs 0.75 1.25 10000 > sortd5

gnuplot -e "set terminal png size 1366, 768; set multiplot layout 2, 1;\
set xlabel 'x'; set ylabel 'p(x)'; set title 'Float, 100 points';\
plot 'sortf3' u 1:2 w l t 'Direct', 'sortf3' u 1:3 w l t 'Horner';\
plot 'sortf3' u 1:4 w l t 'Δ';" > lab2-1-1f.png

gnuplot -e "set terminal png size 1366, 768; set multiplot layout 2, 1;\
set xlabel 'x'; set ylabel 'p(x)'; set title 'Float, 1000 points';\
plot 'sortf4' u 1:2 w l t 'Direct', 'sortf4' u 1:3 w l t 'Horner';\
plot 'sortf4' u 1:4 w l t 'Δ';" > lab2-1-2f.png

gnuplot -e "set terminal png size 1366, 768; set multiplot layout 2, 1;\
set xlabel 'x'; set ylabel 'p(x)'; set title 'Float, 10000 points';\
plot 'sortf5' u 1:2 w l t 'Direct', 'sortf5' u 1:3 w l t 'Horner';\
plot 'sortf5' u 1:4 w l t 'Δ';" > lab2-1-3f.png

gnuplot -e "set terminal png size 1366, 768; set multiplot layout 2, 1;\
set xlabel 'x'; set ylabel 'p(x)'; set title 'Double, 100 points';\
plot 'sortd3' u 1:2 w l t 'Direct', 'sortf3' u 1:3 w l t 'Horner';\
plot 'sortd3' u 1:4 w l t 'Δ';" > lab2-1-1d.png

gnuplot -e "set terminal png size 1366, 768; set multiplot layout 2, 1;\
set xlabel 'x'; set ylabel 'p(x)'; set title 'Double, 1000 points';\
plot 'sortd4' u 1:2 w l t 'Direct', 'sortd4' u 1:3 w l t 'Horner';\
plot 'sortd4' u 1:4 w l t 'Δ';" > lab2-1-2d.png

gnuplot -e "set terminal png size 1366, 768; set multiplot layout 2, 1;\
set xlabel 'x'; set ylabel 'p(x)'; set title 'Double, 10000 points';\
plot 'sortd5' u 1:2 w l t 'Direct', 'sortd5' u 1:3 w l t 'Horner';\
plot 'sortd5' u 1:4 w l t 'Δ';" > lab2-1-3d.png
