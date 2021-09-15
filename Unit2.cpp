//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm2::TreeView1Change(TObject *Sender, TTreeNode *Node)
{
RichEdit1->Lines->Clear();
if(int n=TreeView1->Selected->AbsoluteIndex==0)
{RichEdit1->Lines->LoadFromFile("But.txt");
}
if(int n=TreeView1->Selected->AbsoluteIndex==2)
{RichEdit1->Lines->LoadFromFile("But 1.txt");
}
if(int m=TreeView1->Selected->AbsoluteIndex==3)
{RichEdit1->Lines->LoadFromFile("But 2.txt");
}
if(int m=TreeView1->Selected->AbsoluteIndex==4)
{RichEdit1->Lines->LoadFromFile("But 3.txt");
}
if(int m=TreeView1->Selected->AbsoluteIndex==5)
{RichEdit1->Lines->LoadFromFile("But 5.txt");
}
if(int m=TreeView1->Selected->AbsoluteIndex==6)
{RichEdit1->Lines->LoadFromFile("But 6.txt");
}
if(int m=TreeView1->Selected->AbsoluteIndex==8)
{RichEdit1->Lines->LoadFromFile("But 7.txt");
}
if(int m=TreeView1->Selected->AbsoluteIndex==9)
{RichEdit1->Lines->LoadFromFile("But 8.txt");
}
if(int m=TreeView1->Selected->AbsoluteIndex==10)
{RichEdit1->Lines->LoadFromFile("But 9.txt");
}
if(int m=TreeView1->Selected->AbsoluteIndex==11)
{RichEdit1->Lines->LoadFromFile("But 10.txt");
}
}
//---------------------------------------------------------------------------


