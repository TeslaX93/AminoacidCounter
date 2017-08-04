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

string incString(string incval)
{
int in = atoi(incval.c_str());
in++;
string tmp;
itoa(in,(char*)tmp.c_str(),10);
string incIn = tmp.c_str();

return incIn;
}
string currLine;
string temp = "ZZZ";
string sequence = "";
string seqlong = "";
bool pdbfile = false;
int line_counter = 1;
int pos,atype = 0;
//int n=0; //for testing in future versions
int amino[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int main(int argc, char* argv[])
{
cout<<"\nAminoacidCounter 0.3.0, author TeslaX93 [http://github.com/TeslaX93]"<<endl;
cout<<"With dedication for Paulina W. "<<(char) 3<<endl;
    if(argc>2)
    {

      cout<<"Error: Invalid number of arguments. \n"<<endl;
      cout<<"Usage: AminoacidCounter.exe [path] \n (or simply drag and drop *.mol2 or *.pdb file on program icon) \n"<<endl;
      // -forcepdb -forcemol2 -long
      exit(0);
    }
    if(argc==1) cout<<"Kreator w przygotowaniu."<<endl;
fstream inputfile,outputfile;
inputfile.open(argv[1],ios::in);
outputfile.open("results.txt",ios::out | ios::app);
if(inputfile.good()==false)
    {
       cout<<"File not found or corrupted"<<endl;
       outputfile.close();
       exit(0);
    }
outputfile<<argv[argc-1]<<endl<<endl;
//line_counter = line_counter + n; //for future use

string filename = argv[argc-1];
cout<<"Input file: "<<filename<<endl;
if(showWhereIs(".pdb",filename)!=0) pdbfile=true;
if(!pdbfile) {
    while(getline(inputfile,currLine))
    {
        switch(line_counter) {
        case 1: if(showWhereIs(" Mol2",currLine)==1) {outputfile<<"Mol2 file type detected."<<endl;}
                else if(showWhereIs("EADER",currLine)==1) {pdbfile = true; outputfile<<"Error: Filetype mismatch. Wrong extension. Please contact author."<<endl; }
                else { outputfile<<"Error: Not a valid MOL2/PDB file. Wrong headers or file corrupted."<<endl; inputfile.close(); inputfile.clear(); outputfile.close(); outputfile.clear(); exit(0); }
                break;
        case 2: if((pdbfile) && ((showWhereIs("ITLE",currLine))!=1)) {outputfile<<"Error: Unknown format."<<endl; inputfile.close(); inputfile.clear(); outputfile.close(); outputfile.clear();  exit(0);} break;
        case 3: if((!pdbfile)&&(currLine!="@<TRIPOS>MOLECULE")) {outputfile<<"Error: Unknown format."<<endl; inputfile.close(); inputfile.clear(); outputfile.close(); outputfile.clear(); exit(0);}break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10: break;
        default:
            {
            if(showWhereIs("ALA",currLine)!=0) {pos=showWhereIs("ALA",currLine); atype=1;}
            if(showWhereIs("CYS",currLine)!=0) {pos=showWhereIs("CYS",currLine); atype=2;}
            if(showWhereIs("ASP",currLine)!=0) {pos=showWhereIs("ASP",currLine); atype=3;}
            if(showWhereIs("GLU",currLine)!=0) {pos=showWhereIs("GLU",currLine); atype=4;}
            if(showWhereIs("PHE",currLine)!=0) {pos=showWhereIs("PHE",currLine); atype=5;}
            if(showWhereIs("GLY",currLine)!=0) {pos=showWhereIs("GLY",currLine); atype=6;}
            if(showWhereIs("HIS",currLine)!=0) {pos=showWhereIs("HIS",currLine); atype=7;}
            if(showWhereIs("ILE",currLine)!=0) {pos=showWhereIs("ILE",currLine); atype=8;}
            if(showWhereIs("LYS",currLine)!=0) {pos=showWhereIs("LYS",currLine); atype=9;}
            if(showWhereIs("LEU",currLine)!=0) {pos=showWhereIs("LEU",currLine); atype=10;}
            if(showWhereIs("MET",currLine)!=0) {pos=showWhereIs("MET",currLine); atype=11;}
            if(showWhereIs("ASN",currLine)!=0) {pos=showWhereIs("ASN",currLine); atype=12;}
            if(showWhereIs("PRO",currLine)!=0) {pos=showWhereIs("PRO",currLine); atype=13;}
            if(showWhereIs("GLN",currLine)!=0) {pos=showWhereIs("GLN",currLine); atype=14;}
            if(showWhereIs("ARG",currLine)!=0) {pos=showWhereIs("ARG",currLine); atype=15;}
            if(showWhereIs("SER",currLine)!=0) {pos=showWhereIs("SER",currLine); atype=16;}
            if(showWhereIs("THR",currLine)!=0) {pos=showWhereIs("THR",currLine); atype=17;}
            if(showWhereIs("VAL",currLine)!=0) {pos=showWhereIs("VAL",currLine); atype=18;}
            if(showWhereIs("TRP",currLine)!=0) {pos=showWhereIs("TRP",currLine); atype=19;}
            if(showWhereIs("TYR",currLine)!=0) {pos=showWhereIs("TYR",currLine); atype=20;}

            if((currLine!="@<TRIPOS>BOND")&&(temp!=currLine.substr(pos,6)))
                    {
                    temp=currLine.substr(pos,6);
                    switch(atype)
                        {
                        case 1:  amino[0]++;  amino[20]++; sequence+="A"; seqlong+="Ala"; break;
                        case 2:  amino[1]++;  amino[20]++; sequence+="C"; seqlong+="Cys"; break;
                        case 3:  amino[2]++;  amino[20]++; sequence+="D"; seqlong+="Asp"; break;
                        case 4:  amino[3]++;  amino[20]++; sequence+="E"; seqlong+="Glu"; break;
                        case 5:  amino[4]++;  amino[20]++; sequence+="F"; seqlong+="Phe"; break;
                        case 6:  amino[5]++;  amino[20]++; sequence+="G"; seqlong+="Gly"; break;
                        case 7:  amino[6]++;  amino[20]++; sequence+="H"; seqlong+="His"; break;
                        case 8:  amino[7]++;  amino[20]++; sequence+="I"; seqlong+="Ile"; break;
                        case 9:  amino[8]++;  amino[20]++; sequence+="K"; seqlong+="Lys"; break;
                        case 10: amino[9]++;  amino[20]++; sequence+="L"; seqlong+="Leu"; break;
                        case 11: amino[10]++; amino[20]++; sequence+="M"; seqlong+="Met"; break;
                        case 12: amino[11]++; amino[20]++; sequence+="N"; seqlong+="Asn"; break;
                        case 13: amino[12]++; amino[20]++; sequence+="P"; seqlong+="Pro"; break;
                        case 14: amino[13]++; amino[20]++; sequence+="Q"; seqlong+="Gln"; break;
                        case 15: amino[14]++; amino[20]++; sequence+="R"; seqlong+="Arg"; break;
                        case 16: amino[15]++; amino[20]++; sequence+="S"; seqlong+="Ser"; break;
                        case 17: amino[16]++; amino[20]++; sequence+="T"; seqlong+="Thr"; break;
                        case 18: amino[17]++; amino[20]++; sequence+="V"; seqlong+="Val"; break;
                        case 19: amino[18]++; amino[20]++; sequence+="W"; seqlong+="Trp"; break;
                        case 20: amino[19]++; amino[20]++; sequence+="Y"; seqlong+="Tyr"; break;
                        default: break;
                        }
                    }
            break;
            }
        }
        line_counter++;
        if(currLine=="@<TRIPOS>BOND" || currLine=="@<TRIPOS>SUBSTRUCTURE") break;
    }
}
if(pdbfile) {
    while(getline(inputfile,currLine))
    {
        if((showWhereIs("TOM",currLine)==1)&&(showWhereIs("B",currLine)==0)) {
            if((showWhereIs(" ALA",currLine)!=0)) {pos=showWhereIs(" ALA",currLine); atype=1;}
            if((showWhereIs(" CYS",currLine)!=0)) {pos=showWhereIs(" CYS",currLine); atype=2;}
            if((showWhereIs(" ASP",currLine)!=0)) {pos=showWhereIs(" ASP",currLine); atype=3;}
            if((showWhereIs(" GLU",currLine)!=0)) {pos=showWhereIs(" GLU",currLine); atype=4;}
            if((showWhereIs(" PHE",currLine)!=0)) {pos=showWhereIs(" PHE",currLine); atype=5;}
            if((showWhereIs(" GLY",currLine)!=0)) {pos=showWhereIs(" GLY",currLine); atype=6;}
            if((showWhereIs(" HIS",currLine)!=0)) {pos=showWhereIs(" HIS",currLine); atype=7;}
            if((showWhereIs(" ILE",currLine)!=0)) {pos=showWhereIs(" ILE",currLine); atype=8;}
            if((showWhereIs(" LYS",currLine)!=0)) {pos=showWhereIs(" LYS",currLine); atype=9;}
            if((showWhereIs(" LEU",currLine)!=0)) {pos=showWhereIs(" LEU",currLine); atype=10;}
            if((showWhereIs(" MET",currLine)!=0)) {pos=showWhereIs(" MET",currLine); atype=11;}
            if((showWhereIs(" ASN",currLine)!=0)) {pos=showWhereIs(" ASN",currLine); atype=12;}
            if((showWhereIs(" PRO",currLine)!=0)) {pos=showWhereIs(" PRO",currLine); atype=13;}
            if((showWhereIs(" GLN",currLine)!=0)) {pos=showWhereIs(" GLN",currLine); atype=14;}
            if((showWhereIs(" ARG",currLine)!=0)) {pos=showWhereIs(" ARG",currLine); atype=15;}
            if((showWhereIs(" SER",currLine)!=0)) {pos=showWhereIs(" SER",currLine); atype=16;}
            if((showWhereIs(" THR",currLine)!=0)) {pos=showWhereIs(" THR",currLine); atype=17;}
            if((showWhereIs(" VAL",currLine)!=0)) {pos=showWhereIs(" VAL",currLine); atype=18;}
            if((showWhereIs(" TRP",currLine)!=0)) {pos=showWhereIs(" TRP",currLine); atype=19;}
            if((showWhereIs(" TYR",currLine)!=0)) {pos=showWhereIs(" TYR",currLine); atype=20;}

            if(temp!=currLine.substr(pos,7))
                    {
                        temp=currLine.substr(pos,7);
                        switch(atype)
                        {
                        case 1:  amino[0]++;  amino[20]++; sequence+="A"; seqlong+="Ala"; break;
                        case 2:  amino[1]++;  amino[20]++; sequence+="C"; seqlong+="Cys"; break;
                        case 3:  amino[2]++;  amino[20]++; sequence+="D"; seqlong+="Asp"; break;
                        case 4:  amino[3]++;  amino[20]++; sequence+="E"; seqlong+="Glu"; break;
                        case 5:  amino[4]++;  amino[20]++; sequence+="F"; seqlong+="Phe"; break;
                        case 6:  amino[5]++;  amino[20]++; sequence+="G"; seqlong+="Gly"; break;
                        case 7:  amino[6]++;  amino[20]++; sequence+="H"; seqlong+="His"; break;
                        case 8:  amino[7]++;  amino[20]++; sequence+="I"; seqlong+="Ile"; break;
                        case 9:  amino[8]++;  amino[20]++; sequence+="K"; seqlong+="Lys"; break;
                        case 10: amino[9]++;  amino[20]++; sequence+="L"; seqlong+="Leu"; break;
                        case 11: amino[10]++; amino[20]++; sequence+="M"; seqlong+="Met"; break;
                        case 12: amino[11]++; amino[20]++; sequence+="N"; seqlong+="Asn"; break;
                        case 13: amino[12]++; amino[20]++; sequence+="P"; seqlong+="Pro"; break;
                        case 14: amino[13]++; amino[20]++; sequence+="Q"; seqlong+="Gln"; break;
                        case 15: amino[14]++; amino[20]++; sequence+="R"; seqlong+="Arg"; break;
                        case 16: amino[15]++; amino[20]++; sequence+="S"; seqlong+="Ser"; break;
                        case 17: amino[16]++; amino[20]++; sequence+="T"; seqlong+="Thr"; break;
                        case 18: amino[17]++; amino[20]++; sequence+="V"; seqlong+="Val"; break;
                        case 19: amino[18]++; amino[20]++; sequence+="W"; seqlong+="Trp"; break;
                        case 20: amino[19]++; amino[20]++; sequence+="Y"; seqlong+="Tyr"; break;
                        default:  break;
                        }
                    }
        }
        line_counter++;
    }
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
    outputfile<<"SEQUENCE (short):"<<endl;
    outputfile<<sequence<<endl;
    outputfile<<"SEQUENCE (abbrev.): "<<endl;
    outputfile<<seqlong<<endl;
    outputfile<<endl;
    outputfile.close();
    outputfile.clear();
    inputfile.close();
    inputfile.clear();
    cout << "Operation done. Check for errors in your result file." << endl;

    return 0;
}




/*
MIT License

Copyright (c) 2017 Bartłomiej Malarz [TeslaX93]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

