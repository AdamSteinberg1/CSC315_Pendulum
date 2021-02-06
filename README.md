# Pendulum POC

Pendulum Proof of Concept for CSC 415

### Build and run instructions
```
make
./pendpoc [t_step]
```

The optional command line argument is the time step. It is the amount of simulated time that passes between frames. Put in a small value (like 0.001) to go in slow motion. Put in a large value (like 0.1) to go fast. The default time step is the reciprocal of the FPS, which makes the simulation play in realtime.


### Extra features!  
Left click and drag to move the camera.
