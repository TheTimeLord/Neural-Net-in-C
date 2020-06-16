# Neural-Net-in-C

This is a personal project where I try to make a simple fully connected feed forward neural network in C. Much struggle ahead.


Logs:


June 14, 2020:

I started this project at 3am because I couldn't sleep and I've been having this idea in my head to try and build a neural network in C. It's been a few hours and I think I've made some basic steps towards the beginning of constructing a NN. So far I've built a Dense Node struct that represents a single node in a Dense NN layer. I have some functions that initialize/allocate/free memory for them as well as modify the values of the weights coming into that node. I've run valgrind to check for memory leaks, and I haven't gotten any so far. Looking forward to when there are far too many to count. Small scale testing has gone alright so far. I am going to start cleaning up the codebase next by renaming files and adding headers and testing harnesses. After I am satisfied with the node tests I will start creating a Dense Layer struct.


June 16, 2020:

Once again, I could not sleep so I decided to continue working on this project, again at 3am. I refactored the codebase a bit so I have header files, source files, and a testing harness. I also started working on the Dense Layer struct. However, I ran into a bit of a snag when testing the new struct. It seems to have some issues with memory allocation; it doesn't like how I have node structs nested inside a layer struct having each node individually allocated, initialized, and put into an array inside the layer struct. God that's a mouthful to read. This way of creating layers was probably a dumb idea anyway; I think I wanted to have the ability to change out the type of nodes from dense to another type to build a different kind of layer like a convolutional layer or something. Moving forward I think I am going to refactor the code again, this time doing away with the node struct entirely and reshaping the layer struct to use a 2D array for the weights.
