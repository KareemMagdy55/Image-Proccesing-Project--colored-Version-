#include <iostream>
#include <cstring>
#include "bmplib.cpp"
#include "bmplib.h"
using namespace std;


unsigned char image[SIZE][SIZE][RGB];

void loadImage ();
void filterChoice();
void saveImage ();

int main() {
    loadImage();
    while (1) {
        filterChoice();
    }
}


void loadImage () {
    char imageFileName[100];

    // Get Colored image file name
    cout << "Enter the source image file name:";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}


// Add Your filters here, then unComment your filter function in filter choice function or Add it .

void rotateImage(){

    unsigned char newImage[SIZE][SIZE][RGB];
    int rotationChoice = 1 ;
    cout << "Press 1 for 90 degree rotation\nPress 2 for 180 degree rotation\nPress 3 for 270 degree rotation";
    cin >> rotationChoice;
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


bool isShuffleValid(string& word){
    for(char& c : word){
        if (c != '1' && c!= '2' && c!='3' && c!='4') {
            return false;
        }
    }
    return true;

}
void shuffleImage(){
    unsigned char shuffledImage[SIZE][SIZE][RGB];

    string userShuffle ;
    cout << "Please enter your shuffle order:";
    cin >> userShuffle;

    while (!isShuffleValid(userShuffle) && userShuffle.length() != 4){
        cout << "\nInvalid shuffle order, please re-enter a valid one :\n";

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
                "\nPress 1 for Black & White filter "
                "\nPress 2 for Invert image filter"
                "\nPress 3 to rotate image filter"
                "\nPress 4 to flip image filter"
                "\nPress 5 to darken or lighten filter"
                "\nPress 6 to merge filter"
                "\nPress 7 to enlarge the image"
                "\nPress 8 to shuffle the image"
                "\nPress 9 to save the image"
                "\nPress 0 to Exit"
                "\n-----------------------------------\n";


        cin >> filterChoice;

        if (filterChoice >= 0 && filterChoice <= 9 ) {

            switch (filterChoice) {
                case 0 :
                    exit(0);
                case 1:
                    //BW_filter();
                    validInput = true;
                    break;
                case 2 :
                    //invertFilter();
                    validInput = true;
                    break;
                case 3 :
                    rotateImage();
                    validInput = true;
                    break;
                case 4 :
                    //flipImage();
                    validInput = true;
                    break;
                case 5 :
                    darken_lighten() ;
                    validInput = true;
                    break;
                case 6 :
                    //merge();
                    validInput = true;
                    break;
                case 7 :
                    //enlargeImage();
                    validInput = true;
                    break;
                case 8 :
                    shuffleImage();
                    validInput = true;
                    break;
                case 9 :
                    saveImage();
                    validInput = true;
                    break;
                default:
                    cout << "\nInvalid input, Please try again...\n";
                    break;
            }
        }
    }while (! validInput);


}


