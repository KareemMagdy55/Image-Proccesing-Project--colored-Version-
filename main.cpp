#include <iostream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include "bmplib.h"
#include<cmath>
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
    unsigned char enlargedImage[SIZE][SIZE][RGB];

    int enlargeChoice = 1;
    cout << "\nWhich quarter to enlarge 1, 2, 3 or 4?\n";

    cin >> enlargeChoice;
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
                "\nPress 9 to shrink the image"
                "\nPress 10 to save the image"
                "\nPress 0 to Exit"
                "\n-----------------------------------\n";


        cin >> filterChoice;

        if (filterChoice >= 0 && filterChoice <= 10 ) {

            switch (filterChoice) {
                case 0 :
                    exit(0);
                case 1:
                    //BW_filter();
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
                    //flipImage();
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
                    shrink();
                    validInput = true;
                    break;
                case 10 :
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


