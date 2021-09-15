//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <memory>
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int Col=1;
AnsiString *A,d;



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{StringGrid1->Options
<<goEditing   // Дозволити редагувати
<<goTabs;     // <Tab> перехід до наступної клітинки
int i;
for(i=1;i<StringGrid1->RowCount;i++)
StringGrid1->Cells[0][i]=IntToStr(i);
StringGrid1->Cells[1][0]="Назва фільму";
StringGrid1->Cells[2][0]="Жанр";
StringGrid1->Cells[3][0]="Тривалість (хв)";
StringGrid1->Cells[4][0]="Рік випуску";
StringGrid1->Cells[5][0]="К-сть голосів";
StringGrid1->Cells[6][0]="Рейтинг(к-сть зірок)";
StringGrid1->Cells[0][0]="№";
StringGrid1->ColWidths[1]=110;
StringGrid1->ColWidths[2]=100;
StringGrid1->ColWidths[3]=100;
StringGrid1->ColWidths[4]=100;
StringGrid1->ColWidths[5]=100;
StringGrid1->ColWidths[6]=120;


}
//---------------------------------------------------------------------------
void __fastcall TForm1::StringGrid1KeyPress(TObject *Sender, char &Key)
{
 int cRow, cCol;
 if(Key==VK_RETURN)
 {

   cRow=StringGrid1->Row;
   cCol=StringGrid1->Col;
   if(cCol<StringGrid1->ColCount-1)
     StringGrid1->Col=StringGrid1->Col+1;
   else
     if(cRow<StringGrid1->RowCount-1)
     {
       StringGrid1->Row=StringGrid1->Row+1;
       StringGrid1->Col=1;
     }

 }
if (Col<3){
 if ((Key >= '0') && (Key <= '9')) Key = 0;
}
else {
 if ((Key >= '0') && (Key <= '9') || Key==VK_BACK || Key==VK_RETURN) {}
  else if ( (Key == ',') || (Key == '-')) {}
  else Key = 0;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
int i;
  for(i=1;i<StringGrid1->RowCount;i++)
  StringGrid1->Cells[0][i]=IntToStr(i);
  StringGrid1->Row=StringGrid1->RowCount-1;
  StringGrid1->RowCount++;
  StringGrid1->Row=StringGrid1->RowCount-1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{ int i;
for(i=1;i<StringGrid1->RowCount;i++)
StringGrid1->Cells[0][i]=IntToStr(i);
 int f;
 if(FileExists("File.txt"))
    f=FileOpen("File.txt",fmOpenWrite);
 else
   f=FileCreate("File.txt");

 if(f!=-1)
 {
   for(int i=1;i<StringGrid1->RowCount;i++)
   {
      AnsiString st=StringGrid1->
              Rows[i]->DelimitedText+"\r\n";
      FileWrite(f,st.c_str(),st.Length());
   }
   FileClose(f);
 }
 else
     ShowMessage("Помилка доступу до файлу");



}
 int GetLine(int f,AnsiString *st);
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
Panel1->Visible=true;


}
//---------------------------------------------------------------------------


void __fastcall TForm1::StringGrid1SelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{ Col=ACol;

}
//---------------------------------------------------------------------------
class TPublicGrid: public  TStringGrid
{
    public:
        using TStringGrid::DeleteRow;
};
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{int N =0;
if ( (Edit1->Text >= 0) && (Edit1->Text <= 9) )  N=Edit1->Text.ToInt();
else   {
	MessageBox(this->Handle, "Введіть число!", "Помилка!",
	  MB_OK | MB_ICONERROR);
	return;
  }
((TPublicGrid*)StringGrid1)->DeleteRow(N);
Panel1->Visible=false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
int i,j;
StringGrid1->RowCount=StringGrid1->RowCount+1;
for (j=1; j<StringGrid1->RowCount-1; j++)
for (i=1; i<StringGrid1->RowCount-j-1; i++)
if (StrToInt(StringGrid1->Cells[6][i])!=0 && StrToInt(StringGrid1->Cells[6][i+1])!=0)
if (StrToInt(StringGrid1->Cells[6][i])>StrToInt(StringGrid1->Cells[6][i+1]))
{StringGrid1->Rows[StringGrid1->RowCount+1]=StringGrid1->Rows[i+1];
StringGrid1->Rows[i+1]= StringGrid1->Rows[i];
StringGrid1->Rows[i]=StringGrid1->Rows[StringGrid1->RowCount+1];
}
StringGrid1->RowCount=StringGrid1->RowCount-1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{Chart1->Visible=true;
Series1->Clear();
AnsiString A;
int i,A1=0,A2=0,A3=0,A4=0,A5=0,A6=0,A7=0,A8=0,A9=0,A10=0;
for(int i=1;i<StringGrid1->RowCount;i++)
{
if(StringGrid1->Cells[6][i]==1)
A1=A1+1;
if(StringGrid1->Cells[6][i]==2)
A2=A2+1;
if(StringGrid1->Cells[6][i]==3)
A3=A3+1;
if(StringGrid1->Cells[6][i]==4)
A4=A4+1;
if(StringGrid1->Cells[6][i]==5)
A5=A5+1;
if(StringGrid1->Cells[6][i]==6)
A6=A6+1;
if(StringGrid1->Cells[6][i]==7)
A7=A7+1;
if(StringGrid1->Cells[6][i]==8)
A8=A8+1;
if(StringGrid1->Cells[6][i]==9)
A9=A9+1;
if(StringGrid1->Cells[6][i]==10)
A10=A10+1;
}
 Series1->Add(A1,"1 бал",clRed);
 Series1->Add(A2,"2 бал",clBlue);
 Series1->Add(A3,"3 бал",clGreen);
 Series1->Add(A4,"4 бал",clPurple);
 Series1->Add(A5,"5 бал",clYellow);
 Series1->Add(A6,"6 бал",clBlack);
 Series1->Add(A7,"7 бал",clWhite);
 Series1->Add(A8,"8 бал",clMaroon);
 Series1->Add(A9,"9 бал",clAqua);
 Series1->Add(A10,"10 бал",clGray);
}
//---------------------------------------------------------------------------


String LowCase (String s) {
String Upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
String Lower = "abcdefghijklmnopqrstuvwxyzабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
String s2="",subs;
int pos;
for (int i=1; i<=s.Length(); i++) {
subs = s.SubString(i,1);
pos = Upper.Pos(subs);
s2+=pos>0?Lower.SubString(pos,1):subs;
}
return s2;
}

void __fastcall TForm1::Button10Click(TObject *Sender)
{Panel3->Visible=false;
 int i,j,Row=StringGrid1->Row,found=0;
 if(StringGrid1->RowCount>0){
  String FindStr=LowCase(Edit2->Text);
  for(i=Row+1;i<StringGrid1->RowCount;i++)
  for(j=0;j<StringGrid1->ColCount;j++){
  if(LowCase(StringGrid1->Cells[j][i]).Pos(FindStr)>0){
   StringGrid1->Row=i;
   StringGrid1->Col=j;
   StringGrid1->SetFocus();
   found=1;
   goto out_label;
   }
  }
  out_label:
  if(!found)ShowMessage("Не знайдено!");
 }
 else ShowMessage("Таблиця пуста, пошук неможливий!");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
Panel3->Visible=true;
}
//---------------------------------------------------------------------------






void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
delete []A;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
StringGrid1->RowCount=2;
int f;
AnsiString st;
bool f1=true;
if(OpenDialog1->Execute())
{
TStringList *text_line=new TStringList;
text_line->LoadFromFile(OpenDialog1->FileName);
if((f=FileOpen(OpenDialog1->FileName,fmOpenRead))==-1)
return;
while(GetLine(f,&st)!=0)
{
if(f1)
{
StringGrid1->Rows[StringGrid1->Row]->DelimitedText=st;
f1=false;
}
else
{
StringGrid1->RowCount++;
StringGrid1->Row=StringGrid1->RowCount-1;
StringGrid1->Rows[StringGrid1->Row]->DelimitedText=st;
}}
FileClose(f);}}
//---------------------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender)
{
for(int j=1; j < StringGrid1->RowCount; j++)
for (int i=1; i < StringGrid1->ColCount; i++)
StringGrid1->Cells[i][j]="";         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N5Click(TObject *Sender)
{
Form1->Close();        
}
//---------------------------------------------------------------------------




void __fastcall TForm1::N7Click(TObject *Sender)
{
Form2->Show();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormCreate(TObject *Sender)
{
int f;
  AnsiString st;
  bool f1=true;

  if((f=FileOpen("File.txt",fmOpenRead))==-1)
    return;
  while(GetLine(f,&st)!=0)
  {
     if(f1)
     {
         StringGrid1->Rows[StringGrid1->Row]->DelimitedText=st;
         f1=false;
     }
     else
     {
       StringGrid1->RowCount++;
       StringGrid1->Row=StringGrid1->RowCount-1;
       StringGrid1->Rows[StringGrid1->Row]->DelimitedText=st;
     }
     
  }
  FileClose(f);
}
  int GetLine(int f, AnsiString *st)
  {
     unsigned char buf[256];
     unsigned char *p=buf;

     int n;
     int len=0;

     n=FileRead(f,p,1);
     while(n!=0)
     {
        if(*p=='\r')
        {
           n=FileRead(f,p,1);
           break;
        }
        len++;
        p++;
        n=FileRead(f,p,1);
     }
     *p='\0';
     if(len!=0)
       st->printf("%s",buf);
     return len;        
}
//---------------------------------------------------------------------------







void __fastcall TForm1::N4Click(TObject *Sender)
{
Memo1->Lines->Clear();
if(SaveDialog1->Execute())
{for(int i=0;i<StringGrid1->RowCount;i++)
{StringGrid1->Rows[i+1][0].Delimiter=',';
AnsiString A=StringGrid1->Rows[i+1][0].DelimitedText;
Memo1->Lines->Add(A);}
Memo1->Lines->SaveToFile(SaveDialog1->FileName);}
}
//---------------------------------------------------------------------------

