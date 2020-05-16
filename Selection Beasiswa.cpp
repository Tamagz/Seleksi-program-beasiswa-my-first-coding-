#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void quit			();
void mahasiswa		();
void sign_in		();
void daftar			();
void Data			();
void ADMIN			();
void sorting		();
void searching		();
void tampilan		();
void searching1 	();
void nampilin		();
void cek_status		();
int iyaga			;

int main(){
	
	int pilihan;
	system("CLS");
	tampilan();
	cout<<"1. Mahasiswa \n";
	cout<<"2. Panitia \n";
	cout<<"3. Exit Program \n";
	cout<<"Pilihan : "; cin>>pilihan;
	
	switch (pilihan){
		case 1 :
			mahasiswa();
			break;
		
		case 2 :
			ADMIN();
			break;
			
		case 3:
			quit();
			break;
			
			cin.get();
	}
}

void tampilan(){
	cout<<"|==================================================================================================================| \n";
	cout<<"| 			     		    Program Seleksi Beasiswa       				           |\n";
	cout<<"|          			    		    Kelompok 8                		  			   |\n";
	cout<<"|         			  	    1. Muhammad Rizky Pratama        14117165	   	  	  	   |\n";
	cout<<"|         				    2. Achmad Bany Majesty           14117164	   		   	   |\n";
	cout<<"|           				    3. M Junio Azhari                14117177		  	      	   |\n";
	cout<<"|==================================================================================================================| \n";
}

void mahasiswa(){
	int pilihan;//dah bener
	
	system("CLS");
	tampilan();
	cout<<"1. Sign in \n";
	cout<<"Pilihan : "; cin>>pilihan;
	
	switch (pilihan){
		case 1 :
			sign_in();
			break;
			default:
			mahasiswa();
			cin.get();
	}	
}

//AKUN


void sign_in(){
	system("CLS");
	
	int pilihan;
	string username,password;
	
	string us="prestasi";
	string pass="anak";
cout<<"Username =";cin>>username;
cout<<"Password =";cin>>password;
		system("CLS");
		tampilan();
		if(username==us&&password==pass){
			cout<<"succesfull Logged in! \n";//bingung
		cout<<"Layanan Program Beasiswa : \n";
		cout<<"1. Daftar \n";
		cout<<"2. Data Pendaftar \n";
		cout<<"3. Ke menu utama \n";
		cout<<"4. Cek status\n";
		cout<<"5. Main\n";
		cout<<"Pilihan: ";
		cin>>pilihan;
		
		switch(pilihan){
			case 1 :
				daftar();
				break;
			case 2 :
				Data();
				break;
			case 3:
				main();
				break;
				case 4:
					nampilin();
					break;
					case 5:
						main();
						break;
			default:
				main();
		}
		}else{
			int i;
			for(i=0;i<3;i++){
			
			cout<<"false login! \n";
			sign_in();
		}
}
	
}



void daftar(){
	tampilan();
	struct mahasiswa {
		
	string name,gaji;
	long int nim;
	float ipk;
	};
	
	system("CLS");
	mahasiswa x[100];
	int i,j,n;
	
	ofstream data;
	data.open("Data.txt", ios::app);
	cout<<"Berapa data yang mau dimasukan = ";cin>>n;
	
	for(i=0; i<n; i++){
		cout<<"Nama: "; cin>>x[i].name;
		cout<<"NIM : "; cin>>x[i].nim;
		cout<<"IPK : "; cin>>x[i].ipk;
		if(x[i].ipk<3){
			cout<<"Maaf anda tidak bisa mendaftar. \n";
			quit();
		}
		cout<<"Gaji Orang tua : "; cout<<"Rp."; cin>>x[i].gaji;
	}
	for(i=0; i<n; i++){
		data<<x[i].name<<endl;
		data<<x[i].nim<<endl;
		data<<x[i].ipk<<endl;
		data<<x[i].gaji<<endl;
	}
	data.close();
	cout<<"Data telah diinputkan \n ";
	sign_in();
}


void cek_status(){

nampilin();
	
}


void sorting(){
	system("CLS");
	tampilan();
	struct mahasiswa {
		
	string name;
	long int gaji;
	long int nim;
	float ipk;
	};
	mahasiswa x[100];
	int i,j;
	ofstream sort;
	ifstream sort2;
	char jwb;
	sort2.open("Data.txt") ;
	sort.open("DataSort.txt",ios::app);
	 i=0;
	int count=0;
	while(!sort2.eof()){
		sort2>>x[i].name;
		sort2>>x[i].nim;
		sort2>>x[i].ipk;
		sort2>>x[i].gaji;
		i++;
		count++;
	}
float temp;
			string ganti1;
			long int ganti;
			long int temp1;
	for(i=0; i<count-1; i++){
		for(j=0;j<count-i-1;j++){
		
			
			if(x[j].ipk<x[j+1].ipk){
				ganti=x[j].gaji;
				x[j].gaji=x[j+1].gaji;
				x[j+1].gaji=ganti;
				ganti1=x[j].name;
				x[j].name=x[j+1].name;
				x[j+1].name=ganti1;
				temp1=x[j].nim;
				x[j].nim=x[j+1].nim;
				x[j+1].nim=temp1;
				temp=x[j].ipk;
				x[j].ipk=x[j+1].ipk;
				x[j+1].ipk=temp;
				
	
			}	
		}
	}
	
	for(i=0; i<count-1; i++){
		sort<<x[i].name<<endl;
		sort<<x[i].nim<<endl;
		sort<<x[i].ipk<<endl;
		sort<<x[i].gaji<<endl;
		cout<<"Nama= ";cout<<x[i].name<<endl;
		cout<<"Nim= ";cout<<x[i].nim<<endl;
		cout<<"Ipk= ";cout<<x[i].ipk<<endl;
		cout<<"Gaji= ";cout<<x[i].gaji<<endl;
		
	}
	sort2.close();
	sort.close();
	
	cout<<"\n\n";
	cout<<"kembali ke menu sebelum?(y/n): ";cin>>jwb;
	if(jwb=='y'){
		ADMIN();
	}else{
		quit();
	}
		
}



void Data(){
	struct mahasiswa {
		
	string name,gaji;
	long int nim;
	float ipk;
	};
	int nimm;
	mahasiswa x[100];
	char jwb;
	ifstream data;
	
    system("CLS");
	tampilan();
	int i=0;
	int count=0;
	data.open("Data.txt");
	while(!data.eof()){
		data>>x[i].name;
		data>>x[i].nim;
		data>>x[i].ipk;
		data>>x[i].gaji;
		i++;
		count++;
	}
cout<<"Masukkan NIM = \n";cin>>nimm;
int f;
for( f=0;f<count;f++){
if(nimm==x[f].nim){
	cout<<"Nama= ";cout<<x[f].name<<endl;
		cout<<"Nim= ";cout<<x[f].nim<<endl;
		cout<<"Ipk= ";cout<<x[f].ipk<<endl;
		cout<<"Gaji= ";cout<<x[f].gaji<<endl;
break;
}

}
	cout<<"\n\n";
	cout<<"kembali ke menu sebelum?(y/n): ";cin>>jwb;
	system("CLS");
	tampilan();
	if(jwb=='y'){
		sign_in();
	}else{
		quit();
	}
}

void ADMIN(){
	tampilan();
   string nama,password;
    system("CLS");
	tampilan();
   cout<<"AKUN ADMIN \n\n";
   cout<<"Nama: ";
   cin>>nama;
   cout<<"Password: ";
   cin>>password;
   
   cout<<"\n";
   system("CLS");
	tampilan();
   if((nama=="admin")&&(password=="admin")){
   	cout<<"Login Berhasil\n";
   	cout<<"1. Sorting \n";
   	cout<<"2. Searching\n";
   	cout<<"3. Menu Utama\n";
   	cout<<"4. Quit\n";
   	int pilihan;
   	cout<<"Pilihan: ";
   	cin>>pilihan;
   	
   	switch(pilihan){
   		case 1 :
   			sorting();
   			break;
   		case 2:
   			searching1();
   			break;
   		case 3:
   			main();
			break;
		case 4:
			quit();
			break;
   		default:
   		ADMIN();
	   }
   }else{
   	cout<<"Login gagal\n";
   	ADMIN();
   }
}

void searching1(){
		struct mahasiswa {
		
	string name,gaji;
	long int nim;
	float ipk;
	};
	system("CLS");
	tampilan();
	int nimm;
	char jwb;
	mahasiswa x[100];
	ifstream data;
	int i=0;
	int count=0;
	data.open("Data.txt");
	while(!data.eof()){
		data>>x[i].name;
		data>>x[i].nim;
		data>>x[i].ipk;
		data>>x[i].gaji;
		i++;
		count++;
	}
	cout<<"Masukkan NIM = ";cin>>nimm;
	int f;
	for( f=0;f<count;f++){
		if(nimm==x[f].nim){
		cout<<"Nama= ";cout<<x[f].name<<endl;
		cout<<"Nim= ";cout<<x[f].nim<<endl;
		cout<<"Ipk= ";cout<<x[f].ipk<<endl;
		cout<<"Gaji= ";cout<<x[f].gaji<<endl;
		break;
	}
}
	cout<<"\n\n";
	cout<<"kembali ke menu sebelum?(y/n): ";cin>>jwb;
	if(jwb=='y'){
		ADMIN();
	}else{
		quit();
	}
}



void nampilin(){
	struct mahasiswa {
		
	string name,gaji;
	long int nim;
	float ipk;
	};
	mahasiswa x[100];
	ifstream nampil;
	nampil.open("DataSort.txt");
	int i,count;
	count=0;
	i=0;
	while(!nampil.eof()){
		nampil>>x[i].name;
		nampil>>x[i].nim;
		nampil>>x[i].ipk;
		nampil>>x[i].gaji;
		i++;
		count++;
	}
	int j;
	float temp;
			string ganti1;
			string ganti;
			long int temp1;
	for(i=0; i<count-1; i++){
		for(j=0;j<count-i-1;j++){
			if(x[j].ipk<x[j+1].ipk){
				ganti=x[j].gaji;
				x[j].gaji=x[j+1].gaji;
				x[j+1].gaji=ganti;
				ganti1=x[j].name;
				x[j].name=x[j+1].name;
				x[j+1].name=ganti1;
				temp1=x[j].nim;
				x[j].nim=x[j+1].nim;
				x[j+1].nim=temp1;
				temp=x[j].ipk;
				x[j].ipk=x[j+1].ipk;
				x[j+1].ipk=temp;
				
	
			}	
		}
	}
	for( i=0;i<count-1;i++){
	
		cout<<"Nama= ";cout<<x[i].name<<endl;
		cout<<"Nim= ";cout<<x[i].nim<<endl;
		cout<<"Ipk= ";cout<<x[i].ipk<<endl;
		cout<<"Gaji= ";cout<<x[i].gaji<<endl;
		
}
	
}

void quit(){
	tampilan();
	cout<<"Thank you for using this Program \n";
	system("pause");
	cin.get();
}
