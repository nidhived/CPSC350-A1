  // Nidhi Vedantam
  // 2328859
  // CPSC 350 sec 1

  #include <iostream>
  #include <fstream>
  #include <string>
  #include <cctype>
  #include <cmath>
  using namespace std;

  //main program
  int main(int argc, char** argv) {
    //declaring variables
string userinput = "yes";
while(userinput == "yes"){
    string line;
    double sum =0.0;
    double variance= 0.0;
    double mean;
    string fileName = argv[1];
    string n;
    int totalchar = 0;
    int charline = 0;

    // opening the input and output files
    ifstream inputFile;
    inputFile.open(fileName);

     ofstream outputFile("nidhivedantam.out");
     outputFile << "Nidhi Vedantam" << endl;
     outputFile << "2328859" << endl;
     outputFile << "vedantam@chapman.edu" << endl;


  //to see if the input file is valid, will only continue if it is
     if (!inputFile) {
      cout << "Unable to open file .txt" << endl;
      exit(1); //exit the program
  }

    double totalLines = 0;
    //while loop to keep iterating for each line
    while(getline(inputFile,line)){
      totalchar = 0;
      for(int i= 0; i < line.length(); i++){
        n = line.substr(i,1);
        cout << line[i] << endl;
        //adding total characters
        sum += 1;
        //adding total characters in that line, will reset to 0 after
        totalchar += 1;
        charline += totalchar;
      }
      cout << "Total characters in the line: " << totalchar << endl;
      // make sures it doesn't add empty lines into the calculation for mean and variance
      if(totalchar > 0){
      totalLines++;
      }
    }
  cout << endl;
  cout << "The sum: " << sum << endl;
  //adding the sum of all characters divided by the total lines
  mean = sum/totalLines;
  cout << "The mean: " << mean << endl;



   int totalchar2 = 0;
   double sumvariance = 0;

  //reopening the file to start reading from the top
  inputFile.close();
  inputFile.open(fileName);

  // //calc the numebr of characters in each line for the variance part 2, since now we have to include the mean in the loop
  // also calculating the probability for each possibility
  int numlines = 0;
  //single letters
  double countA = 0;
  double countC = 0;
  double countG = 0;
  double countT = 0;
  //double letters

  //A group
  double countAA = 0;
  double countAC = 0;
  double countAT = 0;
  double countAG = 0;
  //C group
  double countCA = 0;
  double countCC = 0;
  double countCT = 0;
  double countCG = 0;
  //G group
  double countGA = 0;
  double countGC = 0;
  double countGT = 0;
  double countGG = 0;
  //T group
  double countTA = 0;
  double countTC = 0;
  double countTT = 0;
  double countTG = 0;


  char letter;
  //char letter2;

  //probability for single letters
   while(getline(inputFile,line)){
     totalchar2 = 0;

     for(int i= 0; i < line.length(); i++){
       totalchar2 += 1;
       letter = toupper(line[i]);
       //letter2 = toupper(line[i + 1]);

  //counting probability for 'a' with a counter variable
      if(letter == 'A'){
        countA = countA + 1;
      }
  //prob for C
      else if(letter == 'C'){
        countC = countC +1;
      }
  //prob for T
      else if(letter == 'T'){
        countT = countT +1;
      }
  //prob for g
      else if(letter == 'G'){
        countG = countG +1;
      }
    }
    if(totalchar2 > 0){
    sumvariance = (totalchar2 - mean) * (totalchar2 - mean) + sumvariance;
     numlines++;
    }
   }
  //test
  //   cout << sumvariance << endl;
  //  cout << "total char for this line: " << totalchar2 << endl;
  //cout << numlines << endl;



  //calculating the variance and SD
  variance = sumvariance / (numlines);
  cout << "The variance is: " << variance << endl;
  cout << "The standard deviation is: " << sqrt(variance) << endl;
  cout << endl;



  //probability of the single letters
  countA = countA / sum;
  cout << "probability of A: " << countA << endl;
  countC = countC / sum;
  cout << "probability of C: " << countC << endl;
  countT = countT / sum;
  cout << "probability of T: " << countT << endl;
  countG = countG / sum;
  cout << "probability of G: " << countG << endl;
  cout << endl;

  // probability of the double letters
  // another loop to calc the prob of the bigrams since we have to increment in two

  inputFile.close();
  inputFile.open(fileName);

  char doubleletter;
  char doubleletter2;

  while(getline(inputFile,line)){
  //go in increments of two
    for(int i= 0; i < line.length(); i+=2){
      totalchar2 += 1;
      doubleletter = toupper(line[i]);
      doubleletter2 = toupper(line[i + 1]);


  //counting probability for 'a'
     if(doubleletter == 'A'){
       if(doubleletter2 == 'A'){
         //counter only for double letters
         countAA += 1;
       }
       else if(doubleletter2 == 'C'){
         countAC += 1;
       }
       else if(doubleletter2 == 'T'){
         countAT += 1;
       }
       else if(doubleletter2 == 'G'){
         countAG += 1;
       }

     }
  //prob for C
     else if(doubleletter == 'C'){
       if(doubleletter2 == 'A'){
         countCA += 1;
       }
       else if(doubleletter2 == 'C'){
         countCC += 1;
       }
       else if(doubleletter2 == 'T'){
         countCT += 1;
       }
       else if(doubleletter2 == 'G'){
         countCG += 1;
       }
     }
     else if(doubleletter == 'T'){
       if(doubleletter2 == 'A'){
         countTA += 1;
       }
       else if(doubleletter2 == 'C'){
         countTC += 1;
       }
       else if(doubleletter2 == 'T'){
         countTT += 1;
       }
       else if(doubleletter2 == 'G'){
         countTG += 1;
       }
     }
     else if(doubleletter == 'G'){
       if(doubleletter2 == 'A'){
         countGA += 1;
       }
       else if(doubleletter2 == 'C'){
         countGC += 1;
       }
       else if(doubleletter2 == 'T'){
         countGT += 1;
       }
       else if(doubleletter2 == 'G'){
         countGG += 1;
       }
     }

   }
  }

  //a
  //double letter probability output
  countAA = countAA / (sum*.5);
  cout << "probability of AA: " << countAA << endl;
  countAC = countAC / (sum*.5);
  cout << "probability of AC: " << countAC << endl;
  countAT = countAT / (sum*.5);
  cout << "probability of AT: " << countAT << endl;
  countAG = countAG / (sum*.5);
  cout << "probability of AG: " << countAG << endl;
  cout << endl;
  //c
  countCA = countCA / (sum*.5);
  cout << "probability of CA: " << countCA << endl;
  countCC = countCC / (sum*.5);
  cout << "probability of CC: " << countCC << endl;
  countCT = countCT / (sum*.5);
  cout << "probability of CT: " << countCT << endl;
  countCG = countCG / (sum*.5);
  cout << "probability of CG: " << countCG << endl;
  cout << endl;
  //g
  countGA = countGA / (sum*.5);
  cout << "probability of GA: " << countGA << endl;
  countGC = countGC / (sum*.5);
  cout << "probability of GC: " << countGC << endl;
  countGT = countGT / (sum*.5);
  cout << "probability of GT: " << countGT << endl;
  countGG = countGG / (sum*.5);
  cout << "probability of GG: " << countGG << endl;
  cout << endl;
  //t
  countTA = countTA / (sum*.5);
  cout << "probability of TA: " << countTA << endl;
  countTC = countTC / (sum*.5);
  cout << "probability of TC: " << countTC << endl;
  countTT = countTT / (sum*.5);
  cout << "probability of TT: " << countTT << endl;
  countTG = countTG / (sum*.5);
  cout << "probability of TG: " << countTG << endl;
  cout << endl;

  //outputting to file
  outputFile << endl;
  outputFile << "the sum: " << sum << endl;
  outputFile << "The mean: " << mean << endl;
  outputFile << "The variance is: " << variance << endl;
  outputFile << "The standard deviation is: " << sqrt(variance) << endl;
  outputFile << endl;
  outputFile << "probability of A: " << countA << endl;
  outputFile << "probability of C: " << countC << endl;
  outputFile << "probability of T: " << countT << endl;
  outputFile << "probability of G: " << countG << endl;
  outputFile << endl;
  outputFile << "probability of AA: " << countAA << endl;
  outputFile << "probability of AC: " << countAC << endl;
  outputFile << "probability of AT: " << countAT << endl;
  outputFile << "probability of AG: " << countAG << endl;
  outputFile << endl;
  //c
  outputFile << "probability of CA: " << countCA << endl;
  outputFile << "probability of CC: " << countCC << endl;
  outputFile << "probability of CT: " << countCT << endl;
  outputFile << "probability of CG: " << countCG << endl;
  outputFile << endl;
  //g
  outputFile << "probability of GA: " << countGA << endl;
  outputFile << "probability of GC: " << countGC << endl;
  outputFile << "probability of GT: " << countGT << endl;
  outputFile << "probability of GG: " << countGG << endl;
  outputFile << endl;
  //t
  outputFile << "probability of TA: " << countTA << endl;
  outputFile << "probability of TC: " << countTC << endl;
  outputFile << "probability of TT: " << countTT << endl;
  outputFile << "probability of TG: " << countTG << endl;
  outputFile << endl;

  //0-randmax/randmax
  //pairs every other letter of tge loop multiply number by 100 to get range
  //for i in range of D
  double a;
  double b;
  double c;
  double d;

  string DNAstring = "";
  outputFile << "1000 strings: " << endl;

  for (int i = 0; i < 1000; i++) {
    //to change the values of d each time
    a= rand() % RAND_MAX;
    b= rand() % RAND_MAX;
    a/= RAND_MAX;
    b/= RAND_MAX;
    c= sqrt(-2*log(a)) * cos(2 * M_PI * b);
    d= round((sqrt(variance) * c) + mean);
      for(int i =0; i<= d; ++i){

      double prob = ((float)(rand() % 100)/100);
      if(prob <= countA){
        //adding letters to the empty string
        DNAstring = DNAstring + "A";
      }
      else if(prob <= countA + countC){
        DNAstring = DNAstring + "C";
      }
      else if(prob <= countA + countC + countT){
        DNAstring = DNAstring + "T";
      }
      else{
        DNAstring = DNAstring + "G";
      }
    }
    //string will now start on the following line
    DNAstring += "\n";
  }
  outputFile << DNAstring << endl;
  cout << "do you want to re-run the program. enter 'yes' or 'no'" << endl;
  cin >> userinput;


  //closing files
  inputFile.close();
  outputFile.close();

  }
  return 0;
  }
