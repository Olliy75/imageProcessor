#include "ofMain.h"
#include "ofApp.h"
#include "string"

//========================================================================
int main(string path = "test.png", string filter = "greyscale") {
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	//ofRunApp(new ofApp());



	ofImage img;

	img.load("path");
	if (filter == "greyscale")
	{
		// Convert the image to greyscale
		for (int x = 0; x < img.getWidth(); x++) {
			for (int y = 0; y < img.getHeight(); y++) {
				ofColor color = img.getColor(x, y);
				int average = (0.2126 * color.r) + (0.7152 * color.g) + (0.0722 * color.b);
				img.setColor(x, y, ofColor(average));
			}
		}

		// Save the image to a file
		img.save("xyz.jpg");
	}
	else if (filter == "horiFlip") {
		ofImage flippedImg;
		flippedImg.allocate(img.getWidth(), img.getHeight(), img.getImageType());
		for (int x = 0; x < img.getWidth(); x++) {
			for (int y = 0; y < img.getHeight(); y++) {
				int xCord = img.getWidth() - x - 1;
				flippedImg.setColor(x, y, img.getColor(xCord, y));
			}
		}
		flippedImg.save("myCOdeWOrks.jpg");

	}
}
