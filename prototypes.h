void quit(int code);
void process_events();
void display(double theta, double fps, double period);
void step(double & theta, double & omega, double fps);
void init();
double getFPS();
double getPeriod(double omega);
