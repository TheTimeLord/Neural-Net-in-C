# Neural-Net-in-C

This is a personal project where I try to make a simple fully connected feed forward neural network in C. Much struggle ahead.


Logs:

June 14, 2020
I started this project at 3am because I couldn't sleep and I've been having this idea in my head to try and build a neural network in C. It's been a few hours and I think I've made some basic steps towards the beginning of constructing a NN. So far I've built a Dense Node struct that represents a single node in a Dense NN layer. I have some functions that initialize/allocate/free memory for them as well as modify the values of the weights coming into that node. I've run valgrind to check for memory leaks, and I haven't gotten any so far. Looking forward to when there are far too many to count. Small scale testing has gone alright so far. I am going to start cleaning up the codebase next by renaming files and adding headers and testing harnesses. After I am satisfied with the node tests I will start creating a Dense Layer struct.
