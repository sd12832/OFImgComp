# OFImgComp

![N|Solid](https://d28htnjz2elwuj.cloudfront.net/wp-content/uploads/2013/11/San_Jose_State_University_logo.png)

>My fascination with letting images repeat and repeat - or in film's case 'run on' - manifests my belief that we spend much of our lives seeing without observing.  - **Andy Warhol**

This is a project where I first learnt the framework OpenFrameworks. 

Future plans involve creating an online demo of this application using *emscripten*.

I believe that this program will be useful for two sets of people: 

  - People who want to understand how to make an image compositor using *C++* and *OpenFrameworks*. 
  - People who want to see the logic behind an Image Compositor. 
  
# How to Run the Program 

If not on an IDE, compile and run `main.cpp`. Please let me know if this doesn't work. This was create and improved within **XCode** and therefore may not be compliant with other IDEs/ or lack of thereof. If on an IDE such as XCode, simply run the application. The interface should look like the one below. Just drag your first Image to start manipulating the image compositor. 

![sdfsd](https://i.imgur.com/nto6esD.png)

*Note that the above screenshot contains the Image Compositor with an image of the bus schedules leaving to Greyhound Station. 

# Code Description

Most of the code is within the `ofApp.cpp` besides the tipApp.cpp and its header file. The 'Tip Application' provides users with instructions. This should eventually be integrated into the application itself. 

Please let me know if the documentation is scarce at any point and I will make sure to improve it. 

# Tech Used
- *OpenFrameworks*
 
### Todos

- *Import into emscripten for the Javascript portfolio*.
- *Add feature to resize image through UI elements*.

License
----

MIT
