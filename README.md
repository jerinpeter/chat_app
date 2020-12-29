## Testing a simple chat applicatio with talker and listner in ros

# Problems and questions

* I declared 2 topics one to send data from mic to speaker **/tomic** and the other to return data from speaker to mic **/tospeaker** 
* The communication is happening in one direction 
* I was hoping is there any way to write a subscriber and publisher in a single node?
* Write now I did the publishing of the /tospeaker topic in the call back function of the microphone.cpp file
* which is not an apt way, I also tried declaring globally, which says it needs a nodehandle and if declare the nodehandle also globally, then the compiler says there should be an init function before declaring a node handle.
* these are my problems.. any solutions to these?
