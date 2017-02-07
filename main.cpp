#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int showWhereIs(string co, string gdzie) {

    size_t where = 0;

    where = gdzie.find(co);
    if(where!=string::npos) return (int) where;

else return 0;

}

string linia;
string temp = "ZZZ";
string sequence;
int line_counter = 1;
int pos,atype = 0;
int n=0; //for testing in future versions
int amino[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int main(int argc, char* argv[])
{
    cout<<"\nAminoacidCounter 0.1.2, author TeslaX93 [http://github.com/TeslaX93]"<<endl;
    if(argc!=2) {cout<<"Error: Invalid number of arguments. \n"<<endl;
    cout<<"Usage: aacounter.exe [path] \n (or simply drag and drop *.mol2 file on program icon) \n"<<endl;

    exit(0);
    }
    fstream inputfile,outputfile;
    inputfile.open(argv[argc-1],ios::in);
    outputfile.open("results.txt",ios::out | ios::app);
    if(inputfile.good()==false)
    {
       cout<<"File not found"<<endl;
       exit(0);
    }
    outputfile<<argv[argc-1]<<endl<<endl;
    line_counter = line_counter + n; //for future use
    while(getline(inputfile,linia))
    {
        switch(line_counter) {
        case 1: if(!((line_counter==1) && (linia=="# Mol2 written by MVD (www.molegro.com)")))
        { cout<<"Error: Not a valid MOL2 file"<<endl; outputfile.close(); exit(0); } break;
        case 2: break;
        case 3: if(linia!="@<TRIPOS>MOLECULE") {outputfile<<"Error: Unknown format."<<endl; outputfile.close(); exit(0);}break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10: break;
        default:

            {

            if(showWhereIs("ALA",linia)!=0) {pos=showWhereIs("ALA",linia); atype=1;}
            if(showWhereIs("CYS",linia)!=0) {pos=showWhereIs("CYS",linia); atype=2;}
            if(showWhereIs("ASP",linia)!=0) {pos=showWhereIs("ASP",linia); atype=3;}
            if(showWhereIs("GLU",linia)!=0) {pos=showWhereIs("GLU",linia); atype=4;}
            if(showWhereIs("PHE",linia)!=0) {pos=showWhereIs("PHE",linia); atype=5;}
            if(showWhereIs("GLY",linia)!=0) {pos=showWhereIs("GLY",linia); atype=6;}
            if(showWhereIs("HIS",linia)!=0) {pos=showWhereIs("HIS",linia); atype=7;}
            if(showWhereIs("ILE",linia)!=0) {pos=showWhereIs("ILE",linia); atype=8;}
            if(showWhereIs("LYS",linia)!=0) {pos=showWhereIs("LYS",linia); atype=9;}
            if(showWhereIs("LEU",linia)!=0) {pos=showWhereIs("LEU",linia); atype=10;}
            if(showWhereIs("MET",linia)!=0) {pos=showWhereIs("MET",linia); atype=11;}
            if(showWhereIs("ASN",linia)!=0) {pos=showWhereIs("ASN",linia); atype=12;}
            if(showWhereIs("PRO",linia)!=0) {pos=showWhereIs("PRO",linia); atype=13;}
            if(showWhereIs("GLN",linia)!=0) {pos=showWhereIs("GLN",linia); atype=14;}
            if(showWhereIs("ARG",linia)!=0) {pos=showWhereIs("ARG",linia); atype=15;}
            if(showWhereIs("SER",linia)!=0) {pos=showWhereIs("SER",linia); atype=16;}
            if(showWhereIs("THR",linia)!=0) {pos=showWhereIs("THR",linia); atype=17;}
            if(showWhereIs("VAL",linia)!=0) {pos=showWhereIs("VAL",linia); atype=18;}
            if(showWhereIs("TRP",linia)!=0) {pos=showWhereIs("TRP",linia); atype=19;}
            if(showWhereIs("TYR",linia)!=0) {pos=showWhereIs("TYR",linia); atype=20;}
            //if(showWhereIs("@<TRIPOS>BOND",  linia)!=0)
            if((linia!="@<TRIPOS>BOND")&&(temp!=linia.substr(pos,6)))
                    {
                        //cout<<temp<<"="<<linia.substr((size_t) pos,(size_t) 6)<<endl;
                    temp=linia.substr(pos,6);
                    switch(atype)
                        {
                        case 1: amino[0]++; amino[20]++; sequence+="A"; break;
                        case 2: amino[1]++; amino[20]++; sequence+="C";  break;
                        case 3: amino[2]++; amino[20]++; sequence+="D";  break;
                        case 4: amino[3]++; amino[20]++; sequence+="E";  break;
                        case 5: amino[4]++; amino[20]++; sequence+="F";  break;
                        case 6: amino[5]++; amino[20]++; sequence+="G";  break;
                        case 7: amino[6]++; amino[20]++; sequence+="H";  break;
                        case 8: amino[7]++; amino[20]++; sequence+="I";  break;
                        case 9: amino[8]++; amino[20]++; sequence+="K";  break;
                        case 10: amino[9]++; amino[20]++; sequence+="L";  break;
                        case 11: amino[10]++; amino[20]++; sequence+="M";  break;
                        case 12: amino[11]++; amino[20]++; sequence+="N";  break;
                        case 13: amino[12]++; amino[20]++; sequence+="P";  break;
                        case 14: amino[13]++; amino[20]++; sequence+="Q";  break;
                        case 15: amino[14]++; amino[20]++; sequence+="R";  break;
                        case 16: amino[15]++; amino[20]++; sequence+="S";  break;
                        case 17: amino[16]++; amino[20]++; sequence+="T";  break;
                        case 18: amino[17]++; amino[20]++; sequence+="V";  break;
                        case 19: amino[18]++; amino[20]++; sequence+="W";  break;
                        case 20: amino[19]++; amino[20]++; sequence+="Y";  break;
                        default: /*outputfile<<"Error during file processing. Unknown line no. "<<line_counter<<endl; */ break;
                        }
                    }
            break;
            }


        }
        line_counter++;
        if(linia=="@<TRIPOS>BOND" || linia=="@<TRIPOS>SUBSTRUCTURE") break;
    }

    outputfile<<endl;
    outputfile<<"ALA"<<"               "<<amino[0]<<endl;
    outputfile<<"CYS"<<"               "<<amino[1]<<endl;
    outputfile<<"ASP"<<"               "<<amino[2]<<endl;
    outputfile<<"GLU"<<"               "<<amino[3]<<endl;
    outputfile<<"PHE"<<"               "<<amino[4]<<endl;
    outputfile<<"GLY"<<"               "<<amino[5]<<endl;
    outputfile<<"HIS"<<"               "<<amino[6]<<endl;
    outputfile<<"ILE"<<"               "<<amino[7]<<endl;
    outputfile<<"LYS"<<"               "<<amino[8]<<endl;
    outputfile<<"LEU"<<"               "<<amino[9]<<endl;
    outputfile<<"MET"<<"               "<<amino[10]<<endl;
    outputfile<<"ASN"<<"               "<<amino[11]<<endl;
    outputfile<<"PRO"<<"               "<<amino[12]<<endl;
    outputfile<<"GLN"<<"               "<<amino[13]<<endl;
    outputfile<<"ARG"<<"               "<<amino[14]<<endl;
    outputfile<<"SER"<<"               "<<amino[15]<<endl;
    outputfile<<"THR"<<"               "<<amino[16]<<endl;
    outputfile<<"VAL"<<"               "<<amino[17]<<endl;
    outputfile<<"TRP"<<"               "<<amino[18]<<endl;
    outputfile<<"TYR"<<"               "<<amino[19]<<endl;
    outputfile<<"---"<<"               "<<endl;
    outputfile<<"TOTAL"<<"             "<<amino[20]<<endl;
    outputfile<<endl;
    outputfile<<"SEQUENCE:"<<endl;
    outputfile<<sequence<<endl;
    outputfile.close();
    outputfile.clear();
    inputfile.close();
    inputfile.clear();


    cout << "Operation done. Check for errors in your result file." << endl;
    return 0;
}
