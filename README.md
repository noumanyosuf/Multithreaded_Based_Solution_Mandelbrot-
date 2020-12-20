# Multithreaded based solution for Mandelbrot calculation 
<h3>Brief about Mandelbrot</h3>
The term Mandelbrot set is used to refer both to a general class of fractal sets and to a particular instance of such a set. In general, a Mandelbrot set marks the set of points in the complex plane such that the corresponding Julia set is connected and not computable.

The" Mandelbrot set is the set obtained from the quadratic recurrence equation

 z_(n+1)=z_n^2+C 	

with z_0=C, where points C in the complex plane for which the orbit of z_n does not tend to infinity are in the set. Setting z_0 equal to any point in the set that is not a periodic point gives the same result. The Mandelbrot set was originally called a mu molecule by Mandelbrot. J. Hubbard and A. Douady proved that the Mandelbrot set is connected.

Please check https://mathworld.wolfram.com/MandelbrotSet.html and https://www.youtube.com/watch?v=6IWXkV82oyY for more information.

<h3>About the project</h3>
Mandelbrot calculation is very task heavy calculation and to genrate each pixal of the image for each rescale, the every pixal of the image needs to be recalculated. Clearly, this can not be done with a single main thread, and needs well organzied and handled worker thread to for computation.
The Mandelbrot application demonstrates multi-thread programming using Qt. It shows how to use a worker thread to perform heavy computations without blocking the main thread's event loop.
The Mandelbrot application supports zooming and scrolling using the mouse. To avoid freezing the main thread's event loop (and, as a consequence, the application's user interface), we put all the fractal computation in a separate worker thread.  Each worker thread is responsible for calculating one Y scale line of the image, hence there are Widget::height() no of threads created for processing on each resize or zoom event. The thread emits a signal when it is done rendering the fractal.

The application consists of following classes: </br>
JobResult: hold the calculated result of a scale line of the image. </br>
Job: is a QRunnable subclass that calculate the Mandelbrot iteration and emit the job result. </br>
MandelbrotCalculator: is the one which is responsible of creating the Job threads with y pixel position value and then rearrange the processed result from Job threads to a QList for the main thread to dispaly it on the view. </br>
MandelbrotWidget: is a QWidget subclass that shows the Mandelbrot set on screen and lets the user zoom and scroll. </br>

<h3>Mandelbrot image</h3>
 <div align="center">
    <img src="https://github.com/noumanyosuf/Multithreaded_Based_Solution_Mandelbrot-/blob/main/mandelbrot.gif" width="500"</img> 
</div>
