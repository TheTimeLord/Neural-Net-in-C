# Neural-Net-in-C

This is a personal project where I try to make a simple fully connected feed forward neural network in C. Much struggle ahead.


Logs:


June 14, 2020:

I started this project at 3am because I couldn't sleep and I've been having this idea in my head to try and build a neural network in C. It's been a few hours and I think I've made some basic steps towards the beginning of constructing a NN. So far I've built a Dense Node struct that represents a single node in a Dense NN layer. I have some functions that initialize/allocate/free memory for them as well as modify the values of the weights coming into that node. I've run valgrind to check for memory leaks, and I haven't gotten any so far. Looking forward to when there are far too many to count. Small scale testing has gone alright so far. I am going to start cleaning up the codebase next by renaming files and adding headers and testing harnesses. After I am satisfied with the node tests I will start creating a Dense Layer struct.


June 16, 2020:

Once again, I could not sleep so I decided to continue working on this project, again at 3am. I refactored the codebase a bit so I have header files, source files, and a testing harness. I also started working on the Dense Layer struct. However, I ran into a bit of a snag when testing the new struct. It seems to have some issues with memory allocation; it doesn't like how I have node structs nested inside a layer struct having each node individually allocated, initialized, and put into an array inside the layer struct. God that's a mouthful to read. This way of creating layers was probably a dumb idea anyway; I think I wanted to have the ability to change out the type of nodes from dense to another type to build a different kind of layer like a convolutional layer or something. Moving forward I think I am going to refactor the code again, this time doing away with the node struct entirely and reshaping the layer struct to use a 2D array for the weights.

June 21, 2020:

I guess I'm just in the habbit of working in the early hours of the morning now. I dropped the node struct and reworked the layer struct to use 2D arrays for weights of nodes. This seems to be working a bit better. Also I encountered a weird internal compiler error when I was working, but it went away after I rebooted the Virtual Machine. The next step now is to create another struct to represent the input layer and another higher level struct to represent the overall neural network. This will have it's own set of high level functions that the user can use to build the network, similar to the keras libraries in python. Also I will need to create functions for optimizers, learning rates, activations, etc. Both of these tasks will probably be very difficult. The first one will be hard because I might encounter more memory allocation errors like I did before; the second one will be hard because there are many different hyperparameter implementations I have to account for. I also have to code a backpropogation algorithm which will also take forever to do. Overall, I've barely begun, but I'm taking the first steps towards hopefully making something cool.

July 4, 2020:

It's been a while since I last did any work on this project. A lot of distractions came up, and trying to figure out the next step of design was a bit daunting. I ended up deciding to try getting a working set of activation functions. I will probably just use sigmoid and ReLU for now, maybe I'll add more later. After I finish getting some working activation functions, I will probably need to create and input layer struct and a high level neural network struct where all the smaller pieces come together. After that, I can start working on backpropogation.
