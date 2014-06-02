#include <filereading/File.h>


//CONSTRUCTORES
File::File(StadisticIn stadisticIn, string input_name, string output_name, string log_name){
	this->stadisticIn = stadisticIn;
	this->input_name=input_name;
	this->output_name=output_name;
	this->log_name=log_name;
}

File::File() {
	StadisticIn *p = &this->stadisticIn;
	p=NULL;
	this->input_name="";
	this->output_name="";
	this->log_name="";
}
//GETTERS
StadisticIn File::getStadisticIn(){
	return this->stadisticIn;
}

string File::getInput_name(){
	return this->input_name;
}

string File::getOutput_name(){
	return this->output_name;
}

string File::getLog_name(){
	return this->log_name;
}


//SETTERS

void File::setStadisticIn(StadisticIn stadisticIn){
	this->stadisticIn=stadisticIn;
}

void File::setInput_name(string input_name){
	this->input_name=input_name;
}

void File::setOutput_name(string output_name){
	this->output_name=output_name;
}

void File::setLog_name(string log_name){
	this->log_name=log_name;
}

//METODOS
void File::help_printing ()
{
    cout << "Example: executable_name options [ arguments ...]\n" << endl;
    cout << "    -h  --help                  Shows this help\n" << endl;
    cout << "    -i  --input file        	Reads the input file\n" << endl;
    cout << "    -o  --output file           Writes the output file\n" << endl;
    cout << "    -l  --log file              Writes the log file\n" << endl;
}

void File::getOptions(int argc, char **argv){
	int next_opt;
	const char* const short_op = "hiol:" ;
	const struct option long_op[] =
  	{
  	  { "help", 0, NULL, 'h'},
      { "input",         1,  NULL,   'i'},
      { "output",      1,  NULL,   'o'},
      { "log",       1,  NULL,   'l'},
      { NULL,           0,  NULL,   0  }
 	 };
 	const char* input_file = NULL;
  	const char* output_file = NULL ;
  	const char* log_file = NULL;
  	if(argc==1){
  		cout <<"ERROR. THE PROGRAM HAS BEEN EXECUTED WITHOUT PARAMETERS OR OPTIONS"<<endl;
  		help_printing();
  		exit(EXIT_SUCCESS);
  	}
  	while(1){
  		next_opt = getopt_long(argc, argv, short_op, long_op, NULL);
  		if(next_opt==-1){
  			break;
  		}
  		switch(next_opt){
  			case 'h':
  				help_printing();
  				exit(EXIT_SUCCESS);
  			case 'i':
  				input_file = optarg;
  				break;
  			case 'o':
  				output_file = optarg;
  				break;
  			case 'l':
  				log_file = optarg;
  				break;
  			case '?':
  				help_printing();
  				exit(1);
  			case -1 :
  				break;
  			default:
  				abort();
  		}
  	}
  	string ifile(input_file);
  	string ofile(output_file);
  	string lfile(log_file);

  	this->input_name=ifile;
  	this->output_name=ofile;
  	this->log_name=lfile;


}
void File::readInput(){
	string fileName= this->input_name;
	int numproc=0;
	double quantum=0.0;
	string algorithm="";
	string interarrive="";
	double interarriveInter1=0.0;
	double interarriveInter2=0.0;
	string service="";
	double serviceInter1=0.0;
	double serviceInter2=0.0;
	string RP="";
	double RPInter1=0.0;
	double RPInter2=0.0;
	string RIO="";
	double RIOInter1=0.0;
	double RIOInter2=0.0;
	string s;
	string garbage="";
	ifstream inputFile;
	inputFile.open(fileName.c_str());
	if(inputFile.is_open()){

		inputFile >> s >> garbage;
		inputFile >> s >> numproc;
		inputFile >> s >> garbage;
		inputFile >> s >> algorithm;
		if(algorithm=="RR"){
			inputFile >> s >> quantum;
		}
		inputFile >> s >> garbage;
		inputFile >> s >> interarrive;
		inputFile >> s >> interarriveInter1;
		if(interarrive=="uniforme"){
			inputFile >> s >> interarriveInter2;
		}
		inputFile >> s >> garbage;
		inputFile >> s >> service;
		inputFile >> s >> serviceInter1;
		if(service=="uniforme"){
			inputFile >> s >> serviceInter2;
		}
		inputFile >> s >> garbage;
		inputFile >> s >> RP;
		inputFile >> s >> RPInter1;
		if(RP=="uniforme" || RP=="normal"){
			inputFile >> s >> RPInter2;
		}
		inputFile >> s >> garbage;
		inputFile >> s >> RIO;
		inputFile >> s >> RIOInter1;
		if(RIO=="uniforme"){
			inputFile >> s >> RIOInter2;
		}

		inputFile.close();
	}else{
		cout <<"ERROR. The file doesn't exists or there are no permission to open it"<<endl;
	}

	StadisticIn inputStadisticIn=StadisticIn(numproc, quantum, algorithm, interarrive, service, RP, RIO, interarriveInter1, interarriveInter2, serviceInter1, serviceInter2, RPInter1, RPInter2, RIOInter1, RIOInter2);
	this->stadisticIn=inputStadisticIn;

}

void File::writeOutput(){

}

void File::writeLog(){

}
