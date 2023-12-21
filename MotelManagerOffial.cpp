#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>
using namespace std;

bool success = false;

void login(), signup();

//ham chon vai tro ( chu tro hay khach thue )
void ChoseYourRole(int &choice1){
	cout <<"Chon tu cach cua ban"<<endl;
	cout <<"1.Chu tro"<<endl;
	cout <<"2.Nguoi thue"<<endl;
	cout <<"=>Bam nut: "; cin >> choice1; cin.ignore();
}
// ham nhap ma tro va nhap so phong cho khach thue
void inputForUser(string matro, string sophong){
	cout <<"Nhap ma tro: "; getline(cin,matro);
	cout <<"Nhap so phong: "; getline(cin,sophong);	
}

// cac class huong doi tuong
class Khachvanglai{
	private:
		string name, gender;
		string namsinh;
		long sdt;
		string cccd;
	public:
		Khachvanglai(): name(""), gender(""), namsinh(""), sdt(0) {}
		
		void input(){
			cout <<"Ho va ten: "; getline(cin,this->name);
			cout <<"Gioi tinh: "; getline(cin,this->gender);
			cout <<"Ngay/thang/nam sinh: "; getline(cin,this->namsinh);
			cout <<"CCCD: "; getline(cin,this->cccd);
			cout <<"Sdt: "; cin >> this->sdt; cin.ignore();
		}
		void output(){
			cout <<"Ho va ten: "<<this->name<<endl;
			cout <<"Gioi tinh: "<<this->gender<<endl;
			cout <<"Ngay/thang/nam sinh: "<<this->namsinh<<endl;
			cout <<"CCCD: "<<this->cccd<<endl;
			cout <<"Sdt: "<<this->sdt<<endl;
		}
};
class Chutro: public Khachvanglai{
	private:
		string phatSinh;
		long chiphi;
	public:
		Chutro(): Khachvanglai(), phatSinh(""), chiphi(0) {}
		
		void input(){
			Khachvanglai::input();
		}
		void output(){
			Khachvanglai::output();
		}
		
		void nhapPhatSinh(){
			cout << "Nhap ten chi phi phat sinh: "; getline(cin, this -> phatSinh);
		}
		string getPhatsinh(){
			return this->phatSinh;
		}
		void nhapGiaPhatSinh(){
			cout << "Chi phi: "; cin >> this->chiphi; cin.ignore(); 
		}
		long getChiPhi(){
			return this->chiphi;
		}

};
class Khachtro: public Khachvanglai{
	private:
		string quequan;
	public:
		Khachtro(): Khachvanglai(), quequan("") {}
	
		void input(){
			cout <<"--Nhap thong khach tro--"<<endl;
			Khachvanglai::input();
			cout <<"Que quan: "; getline(cin,this->quequan);
		}
		void output(){
			cout <<"--Thong tin khach tro--"<<endl;
			Khachvanglai::output();
			cout <<"Que quan: "<<this->quequan<<endl;
		}
};
//Khu tro, phong tro
class Khutro{
	private:
		string namemotel, addmotel, idmotel, thongbao;
		int sophong;
		long gia1thang;
	public:
		Khutro(): namemotel(""), addmotel(""), idmotel(""), sophong(0), gia1thang(0), thongbao(""){}

		void nhap(){
			cout <<"Ten khu tro: "; getline(cin,this->namemotel);
			cout <<"Dia chi khu tro: "; getline(cin,this->addmotel);
			cout <<"So phong tro: "; cin >> this->sophong; cin.ignore();
			cout <<"Gia thue 1 thang: "; cin >> this->gia1thang; cin.ignore();
			cout <<"ID khu tro: "; getline(cin,this->idmotel);
		}
		void xuat(){
			cout <<"Ten khu tro: "<<this->namemotel<<endl;
			cout <<"Dia chi: "<<this->addmotel<<endl;
			cout <<"So phong tro: "<<this->sophong<<endl;
			cout <<"Gia thue 1 thang: "<<this->gia1thang<<endl;
			cout <<"ID khu tro: "<<this->idmotel<<endl;
		}
		string getNamemotel(){ return this->namemotel; }
		
		void setThongbao(string thongbao){ this->thongbao = thongbao; }
};
class Phongtro : public Khutro{
	private:
		string namemotel,nameroom, detailroom, thongbao;
		long tiendien, tiennuoc, tienguixe, tienrac;
		Khachtro a;
	public:
		Phongtro(): Khutro(), namemotel(""),nameroom(""), detailroom(""), tiendien(0), tiennuoc(0), tienguixe(0), tienrac(0) {}
		void nhap(){
			cout << "Ten khu tro: "; getline(cin, this->namemotel);
			cout <<"Ten phong: "; getline(cin,this->nameroom);
			cout <<"Mo ta phong (dien tich & noi that): "; getline(cin,this->detailroom);
			a.input();
			cout <<"Gia chi phi sinh hoat"<<endl;
			cout <<"Tien dien / kWh : "; cin >> this->tiendien; cin.ignore();
			cout <<"Tien nuoc / khoi: "; cin >> this->tiennuoc; cin.ignore();
			cout <<"Tien gui xe / thang: "; cin >> this->tienguixe; cin.ignore();
			cout <<"Tien rac: "; cin >> this->tienrac; cin.ignore();
		}
		void xuat(){
			cout << "Ten khu tro: " << this->namemotel << endl; 
			cout <<"Ten phong: "<<this->nameroom<<endl;
			cout <<"Mo ta phong (dien tich & noi that): "<<this->detailroom<<endl;
			a.output();
			cout <<"----Gia chi phi sinh hoat----"<<endl;
			cout <<"Tien dien / kWh : "<<this->tiendien<<endl;
			cout <<"Tien nuoc / khoi: "<<this->tiennuoc<<endl;
			cout <<"Tien gui xe / thang: "<<this->tienguixe<<endl;
			cout <<"Tien rac: "<<this->tienrac<<endl;
		}
		string getNamemotel(){ return this->namemotel; }
		string getNameroom(){
			return this->nameroom;
		}
		void setNamemotel(string namemotel){ namemotel = namemotel; }
};

int main(){
	string tb;
	string tk, mk;
	bool run1 = true, run2 = true, run3 = true, run4 = true, run7 = true, run9 = true;
	int choice1, choice2,choice3, choice5, choice6, choice7, index = 0, index1 = 0, index2 = 0, index4 = 0;
	string matro, sophong;
	long total;
	Khachtro khachtro;
	Chutro chutro;
	Khutro ds[100];
	Phongtro pt[100][100];
	long ds2[100]; // chuyen tinh chi phi phat sinh
	string ps[100];
	
    system("cls");
    cout << "  _______  _______ _________ _______  _          _______  _______  _        _______  _______  _______  _______  " << endl;
    cout << " (       )(  ___  )\\__   __/(  ____ \\( \\        (       )(  ___  )( (    /|(  ___  )(  ____ \\(  ____ \\(  ____ ) " << endl;
    cout << " | () () || (   ) |   ) (   | (    \\/| (        | () () || (   ) ||  \\  ( || (   ) || (    \\/| (    \\/| (    )| " << endl;
    cout << " | || || || |   | |   | |   | (__    | |        | || || || (___) ||   \\ | || (___) || |      | (__    | (____)| " << endl;
    cout << " | |(_)| || |   | |   | |   |  __)   | |        | |(_)| ||  ___  || (\\ \\) ||  ___  || | ____ |  __)   |     __) " << endl;
    cout << " | |   | || |   | |   | |   | (      | |        | |   | || (   ) || | \\   || (   ) || | \\_  )| (      | (\\ (    " << endl;
    cout << " | )   ( || (___) |   | |   | (____/\\| (____/\\  | )   ( || )   ( || )  \\  || )   ( || (___) || (____/\\| ) \\ \\__ " << endl;
    cout << " |/     \\|(_______)   )_(   (_______/(_______/  |/     \\||/     \\||/    )_)|/     \\|(_______)(_______/|/   \\__/ " << endl;
    cout << endl;
    cout << endl << "==========================================! WELLCOME TO MOTEL MANEGER !================================================" << endl;

	do{
    	int los;
    	do{
        cout << "1. Dang nhap." << endl << "2. Dang ky." << endl << "=>Bam nut: "; cin >> los; cin.ignore();
    }while(los <= 0 || los > 2);

    switch(los){
        case 1:
            login();
            break;
        case 2:
            signup();
            break;
    }
	
	cout << endl;
	//chon tu cach va dien thong tin
	if(success ==  true){ 
		ChoseYourRole(choice1);
		system("cls");
		//xu ly cac chuc nang
		if(choice1 == 1){
			//nhap thong tin chu tro
			cout <<"--Thong tin chu tro--"<<endl;
			chutro.input(); 
			system("cls");
			do{
				system("cls");
				cout << "  _ __ ___   ___ _ __  _   _  " << endl;
				cout << " | '_ ` _ \\ / _ \\ '_ \\| | | | " << endl;
				cout << " | | | | | |  __/ | | | |_| | " << endl;
				cout << " |_| |_| |_|\\___|_| |_|\\__,_| " << endl;
				cout << "                              " << endl;
				cout <<"1.Them khu tro"<<endl;
				cout <<"2.Danh sach khu tro"<<endl;
				cout <<"3.Thong bao"<<endl;
				cout <<"4.Chi phi phat sinh"<<endl;
				cout <<"5.Thong tin chu tro"<<endl;
				cout <<"6.Dang xuat"<<endl;

				cout <<"=>Bam nut: "; cin >> choice2; cin.ignore();
				switch(choice2){
					// chuc nang 1: 
					case 1:{
						system("cls");
						cout <<"--Them moi khu tro--"<<endl;
						Khutro a;
						a.nhap();
						ds[index] = a;
						index++;
						do{
							cout <<"--------------"<<endl;
						 	cout <<"Ban co muon nhap them khu tro khong?  1.Co / 2.Khong"<<endl;
							do{	
								cout <<"=>Bam nut: "; cin >> choice5; cin.ignore();
								if(choice5<=0||choice5>2) cout <<"Nut bam ko hop le!"<<endl;
						    }while(choice5<=0||choice5>2);
							cout <<"--------------"<<endl;
							switch(choice5){
								case 1:{
									a.nhap();
									ds[index] = a;
									index++;
									break;
								}
								case 2:{
									run4 = false;
									break;
								}
							}
						}while(run4);
						break;
					}
					// chuc nang 2: 
					case 2:{
						
						system("cls");
						cout <<"--Danh sach khu tro--"<<endl;
						for(int i=0;i<index;i++){
							cout <<"Khu tro thu "<<i+1<<endl;
							ds[i].xuat();	
							if(tb.size() == 0 ) cout << "KHONG CO THONG BAO GI!" << endl;
							else cout << "thong bao: " << tb << endl;
							cout <<"-----------------"<<endl;
						}
						cout << "Ban muon xem chi tiet khu tro so may? " << "(1 - " << index << ")" << endl;
						cout << "=> Bam nut: "; cin >> choice6; cin.ignore();
						ds[choice6-1].xuat();

						do{
							cout <<"--------------"<<endl;
							cout <<"1.Them phong"<<endl;
							cout <<"2.Xem phong"<<endl;
							cout <<"3.Quay lai"<<endl;
							cout <<"=>Bam nut: "; cin >> choice7; cin.ignore();
							cout <<"--------------"<<endl;
							switch(choice7){
								case 1:{
									Phongtro x;
									system("cls");
									cout <<"=====Hop Dong Dien Tu====="<<endl;
									x.nhap();
									pt[choice6][index2] = x;
									index2++;
									break;
								}
								case 2:{
									system("cls");
									for(int i = 0; i < index2; i++){
										if(pt[choice6][i].getNameroom()!= ""){
											pt[choice6][i].xuat();
										}
									}
									system("pause");
									break;
								}
								default:
									run7 = false;
									break;								
							}
						}while(run7);
						break;
					}
					case 3:{
						system("cls");
						cout << "Nhap thong bao: "; getline(cin, tb);
						for(int i = 0; i < index; i++){
							ds[i].setThongbao(tb);
						}
						system("pause");
						break;
					}
					case 4:{
						system("cls");
						Chutro b;
						int chonlua;						
						do{
						system("cls");						
						cout <<"--------Chi phi phat sinh---------"<<endl;
						cout << "1. Them ten chi phi phat sinh" << endl << "2. Xem chi phi phat sinh" << endl << "3. Quay lai" << endl << "->Bam nut: "; cin >> chonlua; cin.ignore();
							switch(chonlua){
								case 1:{
									system("cls");
									b.nhapPhatSinh();
									ps[index4] = b.getPhatsinh();
									index4++;
									b.nhapGiaPhatSinh();
									ds2[index1] = b.getChiPhi();
									index1++;
								do{
									int choice9;
									cout << "Ban co muon nhap them chi phi khong?" << endl << "1. Co" << endl << "2. Khong" << endl << "->Bam nut: "; cin >> choice9; cin.ignore();
										switch(choice9){
											case 1:{
												Chutro c;
												system("cls");
												c.nhapPhatSinh();
												ps[index4] = c.getPhatsinh();
												index4++;
												
												c.nhapGiaPhatSinh();
												ds2[index1] = c.getChiPhi();
												index1 ++;
												break;
											}
											case 2:{
												total = 0;
												for(int i=0;i<index4;i++){
													total += ds2[i];
												}
												cout <<"Tong chi phi phat sinh: "<<total<<endl;
												system("pause");
												run9 = false;
												break;
											}	
										}
								}while(run9);
									break;
								}
								case 2:{
									system("cls");
									cout << "------Chi phi phat sinh-------" << endl;
									for(int i = 0; i < index4; i++){
										cout << "Ten chi phi phat sinh: " << ps[i] << endl;
										cout << "Chi phi: " << ds2[i] << endl;
									}
									cout << "Tong chi phi phat sinh: " << total << endl;
									system("pause");
									break;
								}
								default:
									run3 = false;
									break;
							}
							
						}while(run3);
						break;
					}
					case 5:{
						system("cls");
						cout <<"----Thong tin chu tro-----"<<endl;
						chutro.output();
						system("pause");
						break;
					}
					default:
						run2 = false;
						cout <<"Hen gap lai!"<<endl;
						break;
				}

			}while(run2);

		}else if(choice1 == 2){
			int choice4;
			inputForUser(matro,sophong);
			do{
			cout << "  _ __ ___   ___ _ __  _   _  " << endl;
			cout << " | '_ ` _ \\ / _ \\ '_ \\| | | | " << endl;
			cout << " | | | | | |  __/ | | | |_| | " << endl;
			cout << " |_| |_| |_|\\___|_| |_|\\__,_| " << endl;
			cout << "                              " << endl;
			cout <<"1.Thong tin khu tro"<<endl;
			cout <<"2.Thong tin phong tro"<<endl;
			cout <<"3.Dong tien"<<endl;
			cout <<"4.Lien he chu tro"<<endl;
			cout <<"5.Dang xuat"<<endl;
			do{
			cout << "Nhap lua chon cua ban: "; cin >> choice4;
			}while(choice4 < 0 || choice4 > 5);
			}while(true);

		}
	}
	}while(success == false);
	return 0;
}

void login(){
    system("cls");

    cout << "      :::        ::::::::   ::::::::          ::::::::::: ::::    ::: " << endl;
    cout << "     :+:       :+:    :+: :+:    :+:             :+:     :+:+:   :+:  " << endl;
    cout << "    +:+       +:+    +:+ +:+                    +:+     :+:+:+  +:+   " << endl;
    cout << "   +#+       +#+    +:+ :#:                    +#+     +#+ +:+ +#+    " << endl;
    cout << "  +#+       +#+    +#+ +#+   +#+#             +#+     +#+  +#+#+#     " << endl;
    cout << " #+#       #+#    #+# #+#    #+#             #+#     #+#   #+#+#      " << endl;
    cout << "########## ########   ########          ########### ###    ####       " << endl;

    cout << endl ;
    cout << ">><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<" << endl << endl;

    string tk[100], mk[100];
    string username[10], matkhau[10];
    int count = 0, check = 0;
    string acc, pass;

    ifstream taikhoan("D:\\code\\.cpp files\\data\\username.txt", ios :: in);
    ifstream password("D:\\code\\.cpp files\\data\\password.txt", ios :: in);
    taikhoan >> tk[0];
    password >> mk[0];

    cout << "Nhap ten dang nhap: "; cin >> username[0]; cin.ignore();
    while(!taikhoan.eof()){
        getline(taikhoan, acc);
        if(username[0] == acc){
            check++;
        }
    }
    int newacc;
    if(check == 0){
        cout << "Ten dang nhap khong ton tai!" << endl << "Ban co muon tao tai khoan moi ?" << endl;
        do{
            cout << "1. Co." << endl << "2. Khong." << endl << "Nhap lua chon cua ban (1/2): "; cin >> newacc; cin.ignore();
        }while(newacc <= 0 || newacc > 2);

        switch(newacc){
            case(1):
                signup();
                break;
            case(2):
                cout << "Chuc quy khach mot ngay vui ve!"<<endl;
    			exit(0);
        }
    }
    
    cout << "Nhap mat khau:      "; cin >> matkhau[0]; 

    taikhoan.close();
    ifstream account("D:\\code\\.cpp files\\data\\username.txt", ios :: in);
    account >> tk[0];
    while(!account.eof()){
        getline(account, acc);
        getline(password, pass);
        if(username[0] == acc && matkhau[0] == pass){
            cout << "Dang nhap thanh cong!";
            count ++;
			success = true;
            account.close();
            password.close();
            break;
            }
        }
    if(count == 0)
        cout << "Dang nhap khong thanh cong!";
}


void signup(){
    system("cls");
    cout << "      :::::::: ::::::::::: ::::::::  ::::    :::         :::    ::: ::::::::: " << endl;
    cout << "    :+:    :+:    :+:    :+:    :+: :+:+:   :+:         :+:    :+: :+:    :+: " << endl;
    cout << "   +:+           +:+    +:+        :+:+:+  +:+         +:+    +:+ +:+    +:+  " << endl;
    cout << "  +#++:++#++    +#+    :#:        +#+ +:+ +#+         +#+    +:+ +#++:++#+    " << endl;
    cout << "        +#+    +#+    +#+   +#+# +#+  +#+#+#         +#+    +#+ +#+           " << endl;
    cout << "#+#    #+#    #+#    #+#    #+# #+#   #+#+#         #+#    #+# #+#            " << endl;
    cout << "######## ########### ########  ###    ####          ########  ###             " << endl;
    cout << endl << ">><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<>><<" << endl << endl;
    string acc, pass;
    string tk[100], mk[100], mk2[10];
    ifstream taikhoan("D:\\code\\.cpp files\\data\\username.txt", ios :: in);
    ifstream matkhau("D:\\code\\.cpp files\\data\\username.txt", ios :: in);

    ofstream username("D:\\code\\.cpp files\\data\\username.txt", ios :: app); 
    ofstream password("D:\\code\\.cpp files\\data\\password.txt", ios :: app);

    cout << "Nhap ten dang nhap moi: "; cin >> tk[0]; 
        while(!taikhoan.eof()){
            getline(taikhoan, acc);
            if(tk[0] == acc )
                do{
                    cout << "Ten dang nhap bi trung. Vui long nhap lai!" << endl;
                    cout << "Nhap lai ten dang nhap: "; cin >> tk[0]; 
                }while(tk[0] == acc);
        }

    cout << "Nhap mat khau:      "; cin >> mk[0]; 
    cout << "Xac nhan mat khau:  "; cin >> mk2[0];
    if(mk[0] == mk2[0]){
        cout << "Tao tai khoan thanh cong !";
        username << tk[0] << endl;
        password << mk[0] << endl;    
        system("pause");
        system("cls");
        }
    else
        cout << "Sai mat khau!";
    username.close();
    password.close();
}
