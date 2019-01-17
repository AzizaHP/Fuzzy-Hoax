#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct listF{
    string varLinguistik[2];
    double nFuzzyfication[2];
};

typedef struct listF;
listF emosiF,provokasiF, ruleF, tempRuleF;

void fkEmosi(double nEmosi);
void fkProvokasi(double nProvokasi);
double minF(double a, double z);

int main()
{                       //  1     2     3     4      5     6      7       8       9      10     11   12    13     14    15     16     17    18    19      20
    string data_set[20] = {"Ya","Ya","Tidak","Ya","Tidak","Ya","Tidak","Tidak","Tidak","Tidak","Ya","Ya","Tidak","Ya",   "Tidak","Ya","Tidak","Ya","Tidak","Ya"};
    string data_get[20] = {"Ya","Ya","Tidak","Ya","Tidak","Ya","Tidak","Tidak","Ya",   "Tidak","Ya","Ya","Tidak","Tidak","Tidak","Ya","Tidak","Ya","Tidak","Ya"};
    double nEmosi;
    double nProvokasi;
    cout << "Masukkan Nilai Emosi: ";
    cin >> nEmosi;
    fkEmosi(nEmosi);

    cout << "Masukkan Nilai Provokasi: ";
    cin >> nProvokasi;
    fkProvokasi(nProvokasi);

    /*inference*/
    int k = 0;
    for (int i=0; i<2; i++){
        for (int j=k; j<2; j++){
            //k=k+1;
            if ((emosiF.varLinguistik[i]=="Normal") && (provokasiF.varLinguistik[j]=="Normal")){
                ruleF.varLinguistik[k] = "Tidak";
                ruleF.nFuzzyfication[k] = minF(emosiF.nFuzzyfication[i],provokasiF.nFuzzyfication[j]);
            }
            else if ((emosiF.varLinguistik[i]=="Normal") && (provokasiF.varLinguistik[j]=="Sedang")){
                ruleF.varLinguistik[k] = "Tidak";
                ruleF.nFuzzyfication[k] = minF(emosiF.nFuzzyfication[i],provokasiF.nFuzzyfication[j]);
            }
            else if ((emosiF.varLinguistik[i]=="Normal") && (provokasiF.varLinguistik[j] == "Provokasi")){
                ruleF.varLinguistik[k] = "Ya";
                ruleF.nFuzzyfication[k] = minF(emosiF.nFuzzyfication[i],provokasiF.nFuzzyfication[j]);
            }
            else if ((emosiF.varLinguistik[i]=="Sedang") && (provokasiF.varLinguistik[j] == "Normal")){
                ruleF.varLinguistik[k] = "Tidak";
                ruleF.nFuzzyfication[k] = minF(emosiF.nFuzzyfication[i],provokasiF.nFuzzyfication[j]);
            }
            else if ((emosiF.varLinguistik[i]=="Sedang") && (provokasiF.varLinguistik[j] == "Sedang")){
                ruleF.varLinguistik[k] = "Tidak";
                ruleF.nFuzzyfication[k] = minF(emosiF.nFuzzyfication[i],provokasiF.nFuzzyfication[j]);
            }
            else if ((emosiF.varLinguistik[i]=="Sedang") && (provokasiF.varLinguistik[j] == "Provokasi")){
                ruleF.varLinguistik[k] = "Ya";
                ruleF.nFuzzyfication[k] = minF(emosiF.nFuzzyfication[i],provokasiF.nFuzzyfication[j]);
            }
            else if ((emosiF.varLinguistik[i]=="Emosi") && (provokasiF.varLinguistik[j] == "Normal")){
                ruleF.varLinguistik[k] = "Tidak";
                ruleF.nFuzzyfication[k] = minF(emosiF.nFuzzyfication[i],provokasiF.nFuzzyfication[j]);
            }
            else if ((emosiF.varLinguistik[i]=="Emosi") && (provokasiF.varLinguistik[j] == "Sedang")){
                ruleF.varLinguistik[k] = "Ya";
                ruleF.nFuzzyfication[k] = minF(emosiF.nFuzzyfication[i],provokasiF.nFuzzyfication[j]);
            }
            else if ((emosiF.varLinguistik[i]=="Emosi") && (provokasiF.varLinguistik[j] == "Provokasi")){
                ruleF.varLinguistik[k] = "Ya";
                ruleF.nFuzzyfication[k] = minF(emosiF.nFuzzyfication[i],provokasiF.nFuzzyfication[j]);
            }
        //cout << "Nilai fuzzy k: " << ruleF.nFuzzyfication[k] << endl;
        k=k+1;
        }
    }

    /* Nilai Inference
    for (int i=0; i<2; i++){
        if (ruleF.nFuzzyfication[i] != 0 ){
            cout << ruleF.varLinguistik[i] <<" = " << ruleF.nFuzzyfication[i] << endl;
        }
    }*/

    tempRuleF.varLinguistik[0] = ruleF.varLinguistik[0];
    tempRuleF.nFuzzyfication[0] = ruleF.nFuzzyfication[0];

    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            if (tempRuleF.varLinguistik[i]==ruleF.varLinguistik[j]){
                if (tempRuleF.nFuzzyfication[i] < ruleF.nFuzzyfication[j]){
                    tempRuleF.nFuzzyfication[i] = ruleF.nFuzzyfication[j];
                }
            } else {
                tempRuleF.nFuzzyfication[i] = ruleF.nFuzzyfication[i];
                tempRuleF.varLinguistik[i] = ruleF.varLinguistik[i];
            }
        }
        //cout << "Temp i: " << tempRuleF.varLinguistik[i] <<" == "<< tempRuleF.nFuzzyfication[i] << endl;
    }
    //cout << "Temp 1: " << tempRuleF.varLinguistik[0] <<" == "<< tempRuleF.nFuzzyfication[0] << endl;
    //cout << "Temp 2: " << tempRuleF.varLinguistik[1] <<" == "<< tempRuleF.nFuzzyfication[1] << endl;

    /*defuzzyfication*/
    double valueF;
    string hasilF;

    if (tempRuleF.varLinguistik[0]==tempRuleF.varLinguistik[1]){
        if (tempRuleF.nFuzzyfication[0]>tempRuleF.nFuzzyfication[1]){
            valueF = ((15+34)* tempRuleF.nFuzzyfication[0]) / (tempRuleF.nFuzzyfication[0]*2);
        } else {
            valueF = ((70+100)*tempRuleF.nFuzzyfication[1])/(tempRuleF.nFuzzyfication[1]*2);
        }
    }
    else if (tempRuleF.varLinguistik[0]=="Tidak" && tempRuleF.nFuzzyfication[0]!= 0 && tempRuleF.nFuzzyfication[1]==0){
        valueF = ((15+35)* tempRuleF.nFuzzyfication[0]) / (tempRuleF.nFuzzyfication[0]*2);
    }
    else if (tempRuleF.varLinguistik[0]=="Ya" && tempRuleF.nFuzzyfication[0]!= 0 && tempRuleF.nFuzzyfication[1]==0){
        valueF = ((70+100)*tempRuleF.nFuzzyfication[0])/(tempRuleF.nFuzzyfication[0]*2);
    }
    else {
        valueF = (((15+35)*emosiF.nFuzzyfication[0]) + ((70+100)*provokasiF.nFuzzyfication[0]))/
        ((emosiF.nFuzzyfication[0]*2)+(provokasiF.nFuzzyfication[0]*2));
    }

    if (valueF < 50){
        hasilF = "TIDAK";
    } else {
        hasilF = "YA";
    }

    double countDsame = 0;
    int countDdiff = 0;
    for (int i=0;i<20;i++){
        if(data_get[i]==data_set[i]){
            countDsame += 1;
        }
        else {
            countDdiff+=1;
        }
    }

    double akurasi = 0;
    akurasi = ((countDsame/20)*100);

    cout << "Nilai Fuzzy: " << valueF <<endl;
    cout << "Hasil Fuzzy: " << hasilF <<endl;
    cout << "Akurasi    : " << akurasi << " %" << endl;
    cout << endl;
    return 0;
}

void fkEmosi(double nEmosi){
    if (nEmosi <= 30) {
        emosiF.varLinguistik[0] = "Normal";
        emosiF.nFuzzyfication[0] = 1;
    }
    else if ((nEmosi > 30) && (nEmosi < 45)){
        emosiF.varLinguistik[0] = "Normal";
        emosiF.nFuzzyfication[0] = (-(nEmosi-45)/(45-30));
        emosiF.varLinguistik[1] = "Sedang";
        emosiF.nFuzzyfication[1] = ((nEmosi-30)/(45-30));
    }
    else if ((nEmosi >=45) && (nEmosi <=60)){
        emosiF.varLinguistik[0] = "Sedang";
        emosiF.nFuzzyfication[0] = 1;
    }
    else if ((nEmosi >=60) && (nEmosi <=70)){
        emosiF.varLinguistik[0] = "Sedang";
        emosiF.nFuzzyfication[0] = (-(nEmosi-70)/(70-60));
        emosiF.varLinguistik[1] = "Emosi";
        emosiF.nFuzzyfication[1] = ((nEmosi-60)/(70-60));
    }
    else if ((nEmosi > 70) && (nEmosi <= 100)){
        emosiF.varLinguistik[0] = "Emosi";
        emosiF.nFuzzyfication[0] = 1;
    }
    cout << emosiF.varLinguistik[0]<<" " << emosiF.nFuzzyfication[0] << endl;
    cout << emosiF.varLinguistik[1]<<" " << emosiF.nFuzzyfication[1] << endl;
    cout << endl;
}

void fkProvokasi (double nProvokasi){
    if (nProvokasi <=20){
        provokasiF.varLinguistik[0] = "Normal";
        provokasiF.nFuzzyfication[0] = 1;
    }
    else if ((nProvokasi > 20) && (nProvokasi < 30)){
        provokasiF.varLinguistik[0] = "Normal";
        provokasiF.nFuzzyfication[0] = (-(nProvokasi-30)/(30-20));
        provokasiF.varLinguistik[1] = "Sedang";
        provokasiF.nFuzzyfication[1] = ((nProvokasi-20)/(30-20));
    }
    else if ((nProvokasi >= 30) && (nProvokasi <= 55)){
        provokasiF.varLinguistik[0] = "Sedang";
        provokasiF.nFuzzyfication[0] = 1;
    }
    else if ((nProvokasi > 55) && (nProvokasi < 75)){
        provokasiF.varLinguistik[0] = "Sedang";
        provokasiF.nFuzzyfication[0] = (-(nProvokasi-75)/(75-55));
        provokasiF.varLinguistik[1] = "Provokasi";
        provokasiF.nFuzzyfication[1] = ((nProvokasi-55)/(75-55));
    }
    else if ((nProvokasi >= 75) && (nProvokasi <= 100)){
        provokasiF.varLinguistik[0] = "Provokasi";
        provokasiF.nFuzzyfication[0] = 1;
    }
    cout << provokasiF.varLinguistik[0]<<" " << provokasiF.nFuzzyfication[0] << endl;
    cout << provokasiF.varLinguistik[1]<<" " << provokasiF.nFuzzyfication[1] << endl;
    cout << endl;
}

double minF(double a, double z){
    if (a>=z){
        return z;
    } else {
        return a;
    }
}
