clear all
close all
clc

filter = [  
1   0.060   -0.030  -0.168 -0.005
  2   0.067   0.068  -0.074 0.031
  3   0.154   0.094  0.022 0.093
  4   -0.152   0.023  0.065 -0.030
  5   -0.131   -0.043  0.059 -0.081
  6   -0.054   -0.113  -0.008 -0.067
  7   0.012   -0.058  -0.078 -0.027
  8   0.032   -0.003  -0.076 0.002
  9   0.086   0.043  -0.030 0.044
 10   0.462   0.193  0.028 0.253
 11   0.383   0.310  0.115 0.318
 12   0.538   0.461  0.255 0.428
 13   0.453   0.458  0.382 0.440
 14   0.556   0.516  0.452 0.498
 15   0.349   0.453  0.483 0.424
 16   0.415   0.440  0.482 0.419
 17   0.342   0.369  0.447 0.381
 18   0.188   0.315  0.398 0.284
 19   0.131   0.220  0.346 0.208
 20   0.060   0.126  0.264 0.134
 21   0.049   0.080  0.175 0.091
 22   -0.055   0.018  0.105 0.018
 23   -0.012   -0.006  0.052 0.003
 24   -0.178   -0.082  0.003 -0.088
 25   -0.226   -0.139  -0.045 -0.157
 26   -0.391   -0.265  -0.112 -0.274
 27   -0.265   -0.294  -0.200 -0.270
 28   -0.397   -0.351  -0.279 -0.333
 29   -0.283   -0.315  -0.318 -0.308
 30   -0.610   -0.430  -0.337 -0.459
 31   -0.370   -0.421  -0.370 -0.415
 32   -0.342   -0.441  -0.421 -0.379
 33   -0.415   -0.376  -0.436 -0.397
 34   -0.279   -0.345  -0.396 -0.338
 35   -0.240   -0.311  -0.366 -0.289
 36   -0.113   -0.211  -0.326 -0.201
 37   0.004   -0.116  -0.256 -0.098
 38   0.006   -0.034  -0.167 -0.046
 39   0.135   0.048  -0.073 0.044
 40   0.265   0.135  0.007 0.155
 41   0.400   0.267  0.092 0.277
 42   0.447   0.370  0.202 0.362
 43   0.479   0.442  0.316 0.421
 44   0.621   0.516  0.406 0.521
 45   0.474   0.525  0.471 0.497
 46   0.758   0.618  0.526 0.628
 47   0.685   0.639  0.568 0.656
 48   0.564   0.669  0.621 0.610
 49   0.743   0.664  0.662 0.677
 50   0.576   0.628  0.655 0.626
 51   0.515   0.612  0.646 0.571
 52   0.550   0.547  0.624 0.560
 53   0.493   0.520  0.573 0.527
 54   0.347   0.463  0.534 0.437
 55   0.259   0.366  0.491 0.348
 56   0.299   0.301  0.415 0.323
 57   -0.009   0.183  0.327 0.157
 58   0.072   0.121  0.248 0.114
 59   0.194   0.085  0.157 0.154
 60   -0.442   -0.059  0.085 -0.144
 61   -0.026   -0.092  0.032 -0.085
 62   -0.512   -0.327  -0.090 -0.299
 63   -0.270   -0.270  -0.206 -0.285
 64   -0.305   -0.362  -0.283 -0.295
 65   -0.538   -0.371  -0.333 -0.416
 66   -0.534   -0.459  -0.354 -0.475
 67   -0.633   -0.569  -0.424 -0.554
 68   -0.440   -0.536  -0.508 -0.497
 69   -0.456   -0.510  -0.546 -0.476
 70   -0.119   -0.338  -0.514 -0.298
 71   -0.098   -0.224  -0.421 -0.198
 72   0.189   -0.010  -0.279 -0.005
 73   0.170   0.087  -0.117 0.083
 74   0.369   0.242  0.035 0.226
 75   0.466   0.335  0.167 0.346
 76   0.651   0.495  0.286 0.498
 77   0.631   0.583  0.415 0.565
 78   0.771   0.684  0.537 0.668
 79   0.681   0.694  0.629 0.674
 80   0.819   0.757  0.688 0.747
 81   0.762   0.754  0.725 0.754
 82   0.807   0.796  0.753 0.781
 83   0.776   0.782  0.776 0.778
 84   0.820   0.801  0.786 0.799
 85   1.005   0.867  0.798 0.902
 86   0.805   0.877  0.827 0.853
 87   0.872   0.894  0.874 0.863
 88   0.721   0.799  0.880 0.792
 89   0.728   0.774  0.842 0.760
 90   0.689   0.713  0.791 0.725
 91   0.646   0.688  0.740 0.685
 92   0.592   0.642  0.703 0.639
 93   0.679   0.639  0.667 0.659
 94   0.335   0.535  0.633 0.497
 95   0.447   0.487  0.591 0.472
 96   0.210   0.330  0.506 0.341
 97   0.323   0.000  0.000 0.000
 98   -0.113   0.000  0.000 0.105
 99   0.320   0.177  0.000 0.212
100   0.016   0.074  0.000 0.114
    
];
%plot the result
figure;

hold on
plot(filter(:,2),'linewidth',2);
plot(filter(:,3),'linewidth',2);
plot(filter(:,4),'linewidth',2);
plot(filter(:,5),'linewidth',2);
hold off

xlabel('index')
ylabel('acceleration(g)');
title('raw z acceleration and filter results')
legend('raw','maf','fir','iir')



