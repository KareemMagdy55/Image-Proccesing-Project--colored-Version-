/*

        Purpose: Colored-RGB image processor allows you to load an image and
                 apply some filters or changes to it, then save it again.
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include "bmplib.h"
#include<cmath>

using namespace std;
unsigned char image[SIZE][SIZE][RGB];

void loadImage ();  // To load the image from the program file path
void filterChoice();// Makes the user choose which filter to apply to his image
void saveImage ();  // To save the edited image to the program file path
// All 12 filters:
void BW_filter();
void flipImage();
void detect_edges();
void mirror();
void shrink();
void blur();
void shuffleImage();
void enlargeImage();
void merge();
void darken_lighten() ;
void rotateImage();
void invertFilter();


int main() {
    loadImage();
    while (1) {
        filterChoice(); //Endless loop as the user can choose to exit the program
    }
}


void loadImage () {
    char imageFileName[100];
    bool imgValidation = false;

    while (!imgValidation) {
        // Get colored image file name
        cout << "Enter the source image file name:";
        cin >> imageFileName;

        // Add to it .bmp extension and load image
        strcat(imageFileName, ".bmp");


        if (! readRGBBMP(imageFileName, image)) {
            imgValidation = true;
        }
        else { //if the Image is not valid, reRun loadImage()
            cout << "\nImage not found, Please try again.\n";
        }
    }
}




void rotateImage(){
       
    unsigned char newImage[SIZE][SIZE][RGB];
       
    int rotationChoice = 1 ;
    cout << "Press 1 for 90 degree rotation\nPress 2 for 180 degree rotation\nPress 3 for 270 degree rotation";
    cin >> rotationChoice;
       
    while (rotationChoice < 1 || rotationChoice > 3){
           
           cout << "\nInvalid input, please re-enter a valid one :\n";
           cin >> rotationChoice;
    }     
       
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; ++k) {


                switch (rotationChoice) {
                    case 1 :
                        // 90 degree rotation
                        newImage[i][j][k] = image[SIZE - 1 - j][i][k];
                        break;
                    case 2 :
                        // 180 degree rotation
                        newImage[i][j][k] = image[SIZE - 1 - i][SIZE - 1 - j][k];
                        break;
                    case 3 :
                        // 270 degree rotation
                        newImage[i][j][k] = image[j][SIZE - 1 - i][k];
                        break;
                    default :
                        break;
                }
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {


                image[i][j][k] = newImage[i][j][k];
            }
        }
    }
}

bool isShuffleValid(string& word){
    for(char& c : word){
        if (c != '1' && c!= '2' && c!='3' && c!='4') {
            return false;
        }
    }
    return true;

}
void shuffleImage(){
    // The Shuffle image filter allows the user to rearrange the image four quarters in the order he want .
    unsigned char shuffledImage[SIZE][SIZE][RGB];

    string userShuffle ;
    cout << "Please enter your shuffle order:";
    cin >> userShuffle;

    // check if the shuffle order user entered is valid or not .
    while (!isShuffleValid(userShuffle) && userShuffle.length() != 4){
        cout << "\nInvalid shuffle order, please re-enter a valid one :\n";
        cin >> userShuffle;

    }


    for (int k = 0; k < 4; ++k) {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int l = 0; l < RGB; ++l) {


                    switch(k) {
                        case 0 :
                            switch (userShuffle[k]) {
                                case '1':
                                    shuffledImage[i / 2][j / 2][l] = image[i / 2][j / 2][l];
                                    break;
                                case '2':
                                    shuffledImage[i / 2][j / 2][l] = image[i / 2][SIZE / 2 + j / 2][l];
                                    break;
                                case '3' :
                                    shuffledImage[i / 2][j / 2][l] = image[SIZE / 2 + i / 2][j / 2][l];
                                    break;
                                case '4' :
                                    shuffledImage[i / 2][j / 2][l] = image[SIZE / 2 + i / 2][SIZE / 2 + j / 2][l];
                                    break;
                            }
                            break;

                        case 1 :
                            switch (userShuffle[k]) {
                                case '1':
                                    shuffledImage[i / 2][SIZE / 2 + j / 2][l] = image[i / 2][j / 2][l];
                                    break;
                                case '2':
                                    shuffledImage[i / 2][SIZE / 2 + j / 2][l] = image[i / 2][SIZE / 2 + j / 2][l];
                                    break;
                                case '3' :
                                    shuffledImage[i / 2][SIZE / 2 + j / 2][l] = image[SIZE / 2 + i / 2][j / 2][l];
                                    break;
                                case '4' :
                                    shuffledImage[i / 2][SIZE / 2 + j / 2][l] = image[SIZE / 2 + i / 2][SIZE / 2 + j / 2][l];
                                    break;
                            }
                            break;
                        case 2 :
                            switch (userShuffle[k]) {
                                case '1':
                                    shuffledImage[SIZE / 2 + i / 2][j / 2][l] = image[i / 2][j / 2][l];
                                    break;
                                case '2':
                                    shuffledImage[SIZE / 2 + i / 2][j / 2][l] = image[i / 2][SIZE / 2 + j / 2][l];
                                    break;
                                case '3' :
                                    shuffledImage[SIZE / 2 + i / 2][j / 2][l] = image[SIZE / 2 + i / 2][j / 2][l];
                                    break;
                                case '4' :
                                    shuffledImage[SIZE / 2 + i / 2][j / 2][l] = image[SIZE / 2 + i / 2][SIZE / 2 + j / 2][l];
                                    break;
                            }
                            break;
                        case 3 :
                            switch (userShuffle[k]) {
                                case '1':
                                    shuffledImage[SIZE / 2 + i / 2][SIZE / 2 + j / 2][l] = image[i / 2][j / 2][l];
                                    break;
                                case '2':
                                    shuffledImage[SIZE / 2 + i / 2][SIZE / 2 + j / 2][l] = image[i / 2][SIZE / 2 + j / 2][l];
                                    break;
                                case '3' :
                                    shuffledImage[SIZE / 2 + i / 2][SIZE / 2 + j / 2][l] = image[SIZE / 2 + i / 2][j / 2][l];
                                    break;
                                case '4' :
                                    shuffledImage[SIZE / 2 + i / 2][SIZE / 2 + j / 2][l] = image[SIZE / 2 + i / 2][SIZE / 2 +j / 2][l];
                                    break;
                            }
                            break;


                    }

                }
            }
        }

    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                image[i][j][k] = shuffledImage[i][j][k];
            }
        }
    }


}

void invertFilter(){
    // every colored pixel is turned to opposite level of brightness  (255 – pixel value)

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            for (int k = 0; k < RGB; ++k) {

                image[i][j][k] = 255 - image[i][j][k];
            }
        }
    }

}

void enlargeImage() {
       // The Enlarge filter lets user extract one of the four picture quadrants into a single 256 * 256 image.
       
    unsigned char enlargedImage[SIZE][SIZE][RGB];

    int enlargeChoice = 1 ;
    cout << "\nWhich quarter to enlarge 1, 2, 3 or 4?\n";
    cin >> enlargeChoice;
       
    while (enlargeChoice < 1 || enlargeChoice > 4){
           
           cout << "\nInvalid input, please re-enter a valid one :\n";
           cin >> enlargeChoice;
    }   
       
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; ++k) {

                switch (enlargeChoice) {
                    case 1 :
                        // first quarter
                        enlargedImage[i][j][k] = image[i / 2][j / 2][k];
                        break;
                    case 2 :
                        // second quarter
                        enlargedImage[i][j][k] = image[i / 2][SIZE / 2 + j / 2][k];
                        break;
                    case 3 :
                        // third quarter
                        enlargedImage[i][j][k] = image[SIZE / 2 + i / 2][j / 2][k];
                        break;
                    case 4 :
                        // Fourth quarter
                        enlargedImage[i][j][k] = image[SIZE / 2 + i / 2][SIZE / 2 + j / 2][k];
                        break;
                    default :
                        break;
                }
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {


                image[i][j][k] = enlargedImage[i][j][k];
            }
        }
    }
}


void darken_lighten(){
    unsigned char image2[SIZE][SIZE][RGB];
    int choice ;
    cout <<"enter 0 to darken or 1 to lighten : ";
    cin >> choice;
    if (choice == 0 ){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < RGB; ++k) {

                    image2[i][j][k] = (image[i][j][k] / 2 );
                }

            }
        }
    }
    else if (choice==1){
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k <RGB ; ++k) {

                    image2[i][j][k] =  (pow(image[i][j][k],.8)-120) ;
                }

            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k <RGB ; ++k) {
                image[i][j][k]=image2[i][j][k];

            }
        }
    }
}


void merge() {

    //declare our needed images

    unsigned char image2[SIZE][SIZE][RGB];
    unsigned char image3[SIZE][SIZE][RGB];
    char imageFileName2[100];

//input second image to merge

    cout << "Enter the source image2 file name:";
    cin >> imageFileName2;

//adding (.bmp) to 2nd image

    strcat (imageFileName2, ".bmp");
    readRGBBMP(imageFileName2, image2);


    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k <RGB ; ++k) {
                image3[i][j][k] = (image[i][j][k] + image2[i][j][k]) / 2 ;
            }

        }
    }

//for loop to put 3rd image in our original image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k <RGB ; ++k) {
                image[i][j][k] = image3[i][j][k] ;
            }

        }
    }

}

void shrink(){

    unsigned char image2 [SIZE][SIZE][RGB];


    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                image2[i][j][k] = 255;

            }

        }

    }

    int option ;
    cout <<"for 1/2 shrink photo press 1 : \n";
    cout <<"for 1/3 shrink photo press 2 : \n";
    cout <<"for 1/4 shrink photo press 3 : \n";

    cin >> option ;

    if (option == 1)
    {
        for (int i = 0; i < SIZE; i+= 2) {
            for (int j = 0; j < SIZE; j+= 2) {
                for (int k = 0; k < 3; ++k) {
                    image2[i / 2][j / 2][k] = image[i][j][k] ;
                }
            }
        }
    }

    else if (option == 2)
    {
        for (int i = 0; i < SIZE; i+= 3) {
            for (int j = 0; j < SIZE; j+= 3) {
                for (int k = 0; k < RGB; ++k) {
                    image2[i / 3][j / 3][k] = image[i][j][k] ;
                }
            }
        }
    }

    else if (option == 3)
    {
        for (int i = 0; i < SIZE; i+= 4) {
            for (int j = 0; j < SIZE; j+= 4) {
                for (int k = 0; k < RGB; ++k) {
                    image2[i / 4][j / 4][k] = image[i][j][k] ;
                }
            }
        }
    }

    for (int i=0 ; i < SIZE;i++){
        for (int j =0 ; j< SIZE;j++){
            for (int k=0 ; k< RGB;k++){
                image[i][j][k]=image2[i][j][k];
            }
        }
    }

}

void BW_filter(){
    //This filter turns a colored image to a 2 shades image (black and white)
    //white colored pixel --> Red = 255, Green = 255, Blue = 255
    //black colored pixel --> Red = 0, Green = 0, Blue = 0

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            //Average values of the three colors of a pixel:
            double pixel_avg = (image[i][j][0] + image[i][j][1] + image[i][j][2])/3;

            if (pixel_avg > 127){
                // every pixel above 127 will be white colored pixel
                image[i][j][0] = 255 ;
                image[i][j][1] = 255 ;
                image[i][j][2] = 255 ;
            }else{
                // every pixel under 127 will be black colored pixel
                image[i][j][0] = 0 ;
                image[i][j][1] = 0 ;
                image[i][j][2] = 0 ;
            }
        }
    }

}

void flipImage(){
    //This filter allows the user to flip the image
    //horizontally or vertically, as if it is reflected on mirror
    string type_of_flip;
    unsigned char clone[SIZE][SIZE][RGB]; //3D array that has the same size as the image

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                //copying the image pixels values into "clone" 3D array
                clone[i][j][k] = image[i][j][k];
            }
        }
    }

    cout << "\nFlip (H)orizontally or (V)ertically ?\n";
    cin >> type_of_flip; // Take the type of the flip from user
    while (true) {
        if (type_of_flip == "h"||type_of_flip == "H") {
            // To flip the image "Horizontally"
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; k++) {

                        image[i][j][k] = clone[i][255 - j][k]; //Flipping the matrix values horizontally
                    }
                }
            }
            break;//breaks the biggest loop after flipping the image horizontally
        }
        else if (type_of_flip == "v"||type_of_flip == "V"){
            // To flip the image "Vertically"
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; k++) {

                        image[i][j][k] = clone[255 - i][j][k]; //Flipping the matrix values vertically
                    }
                }
            }
            break; //breaks the biggest loop after flipping the image vertically
        }
        else{
            //if the user did not enter (H or V) it asks him to re-enter type_of_flip again
            cout << "invalid input! please enter H or V..." << endl;
            cin >> type_of_flip;
        }
    }

}

void detect_edges(){
    //This function finds the edges of the drawings in the image and turns the
    //image into a skeleton version of the original as if it is drawn with pencil
    //without coloring (black and white version but only edges are black colored)

    BW_filter(); //turn the image into Black and White Image
    unsigned char clone[SIZE][SIZE][RGB]; //3D array that has the same size as the image

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < RGB; k++) {
                //copying the image pixels values into "clone" 3D array
                clone[i][j][k] = image[i][j][k];
            }
        }
    }

    for (int i = 1; i < 255; i++) {
        for (int j = 1; j < 255; j++) {
            for (int k = 0; k < RGB; k++) {

                //In the B&W version, this if statement checks if all pixels around the
                //current pixel are black pixels, and if so
                //it turns the current pixel into a white colored pixel
                if (clone[i - 1][j - 1][k] == 0 and clone[i - 1][j][k] == 0 and clone[i - 1][j + 1][k] == 0
                    and clone[i][j - 1][k] == 0 and clone[i][j + 1][k] == 0
                    and clone[i + 1][j - 1][k] == 0 and clone[i + 1][j][k] == 0 and clone[i + 1][j + 1][k] == 0) {
                    image[i][j][k] = 255;
                }
            }
        }
    }
}

void mirror(){
    //This filter mirrors any half of the image
    //Left half, Right half, Upper half, or Lower half.

    string type_of_mirror;
    cout<< "\nPlease Choose type of mirror to apply to your image\n"
        << "\nPress 1 for Left Half "
        << "\nPress 2 for Right Half"
        << "\nPress 3 for Upper Half"
        << "\nPress 4 for Lower Half" << endl;
    cin >> type_of_mirror;

    while (true) {
        if (type_of_mirror == "1") { //Left Half Mirror
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < 128; j++) {
                    for (int k = 0; k < RGB; k++) {
                        //copying pixels of the left half into the right half in a flipped order
                        image[i][255 - j][k] = image[i][j][k];
                    }
                }
            }
            break;
        }
        else if (type_of_mirror == "2"){ //Right Half Mirror
            for (int i = 0; i < SIZE; i++) {
                for (int j = 128; j < 256; j++) {
                    for (int k = 0; k < RGB; k++) {
                        //copying pixels of the right half into the left half in a flipped order
                        image[i][255-j][k] = image[i][j][k];
                    }
                }
            }
            break;
        }
        else if (type_of_mirror == "3"){ //Upper Half Mirror
            for (int i = 0; i < 128; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; k++) {
                        //copying pixels of the upper half into the lower half in a flipped order
                        image[255 - i][j][k] = image[i][j][k];
                    }
                }
            }
            break;
        }
        else if (type_of_mirror == "4"){ //Lower Half Mirror
            for (int i = 128; i < 256; i++) {
                for (int j = 0; j < SIZE; j++) {
                    for (int k = 0; k < RGB; k++) {
                        //copying pixels of the lower half into the upper half in a flipped order
                        image[255 - i][j][k] = image[i][j][k];
                    }
                }
            }
            break;
        }
        else{
            //if the user did not enter (1 - 4) it asks him to re-enter type_of_mirror again
            cout << "\n invalid input... please try again" << endl;
            cin >> type_of_mirror;
        }
    }
}

void blur(){
    long long avg=0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int m=0;m<3;m++){
                for (int k = i; k < i+7; k++) {
                    for (int l = j; l < j+7; l++)
                        avg+=(image[k][l][m]);
                }
                avg=avg/49;
                image[i][j][m]=avg;
                avg=0;
            }
        }
    }
}

void saveImage () {
    char imageFileName[100];

    // Get Colored image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}

void filterChoice(){
    bool validInput = false ;

    do {
        int filterChoice = 0;
        cout << "\n-----------------------------------\n"
                "Please Choose a filter to apply it to your image\n"
                "\nPress 1 to save the image"
                "\nPress 2 for Invert image filter"
                "\nPress 3 to rotate image filter"
                "\nPress 4 to flip image filter"
                "\nPress 5 to darken or lighten filter"
                "\nPress 6 to merge filter"
                "\nPress 7 to enlarge the image"
                "\nPress 8 to shuffle the image"
                "\nPress 9 to blur the image"
                "\nPress 10 to shrink the image"
                "\nPress 11 to detect image edges"
                "\nPress 12 to mirror image"
                "\nPress 13 for Black & White filter "
                "\nPress 0 to Exit"
                "\n-----------------------------------\n";


        cin >> filterChoice;

        if (filterChoice >= 0 && filterChoice <= 13) {

            switch (filterChoice) {
                case 0 :
                    exit(0);
                case 1 :
                    saveImage();
                    validInput = true;
                    break;
                case 2 :
                    invertFilter();
                    validInput = true;
                    break;
                case 3 :
                    rotateImage();
                    validInput = true;
                    break;
                case 4 :
                    flipImage();
                    validInput = true;
                    break;
                case 5 :
                    darken_lighten() ;
                    validInput = true;
                    break;
                case 6 :
                    merge();
                    validInput = true;
                    break;
                case 7 :
                    enlargeImage();
                    validInput = true;
                    break;
                case 8 :
                    shuffleImage();
                    validInput = true;
                    break;
                case 9 :
                    blur();
                    validInput = true;
                    break;
                case 10 :
                    shrink();
                    validInput = true;
                    break;
                case 11 :
                    detect_edges();
                    validInput = true;
                    break;
                case 12 :
                    mirror();
                    validInput = true;
                    break;
                case 13:
                    BW_filter();
                    validInput = true;
                    break;
                default:
                    cout << "\nInvalid input, Please try again...\n";
                    break;
            }
        }
    }while (! validInput);




}


