�����������
fatal error C1189: #error :WINDOWS.H already included.

�����������˶���Ԥ����ĺ�
#ifdef _WINDOWS_
#undef _WINDOWS_     #include <afx.h>
#endif


CAA���ô��빹��
#include<afxwin.h>
AfcMessageBox(_T("hello!Point Command"));

//�����ͱ��ʽת�����ַ���
//ʹ���ַ����������ʵ��ת���������
#define PR(x) cout<<#x"="<<x<<"\n";
1��CATDlgNotify
	CATUnicodeString NotifyText;
	//NotifyText.BuildFromNum(iInputAllocatedSize);
	_OpenNotify = new CATDlgNotify(this, "TEST", CATDlgNfyWarning|CATDlgNfyOK);
	_OpenNotify->SetText(NotifyText);
	_OpenNotify->SetVisibility(CATDlgShow);

2��CATUnicodeString -->LPSTR ����CString  afxstr;
	CATUnicodeString InstanceName;
	spProduct->GetPrdInstanceName(InstanceName);
	CString name=InstanceName.ConvertToChar();
	MessageBox(NULL,name,L"OK",MB_OK | MB_SYSTEMMODAL);
	MessageBox(NULL,L"Hello World!",L"�ɹ�",MB_OK | MB_SYSTEMMODAL);

	CString str;  
    str.Format(_T("%d"),len); //CString���һ����Ա����,��ͨ����ʽ����ʹ�������͵�����ת����һ���ַ���

3��Ԫ����������ʾ

/**
* ����Ԫ��
* @param ipListElemObj
* Ԫ���б�
*/
void BasicGlobalFunc::HideElements(CATLISTV(CATISpecObject_var) ipListElemObj)
{
	for(int i=1;i<ipListElemobj.Size();i++;)
	{
		CATIVisProperties* pPropONElem = NULL;
		HRESULT rc = ipListElemobj[i]->QueryInterface(IID_CATIVisProperties,(void**) &pPropONElem );
		if (NULL != pPropONElem) 
		{
			CATIVisPropertiesValues PropValue;
			CATIVisPropertyType PropTypeOnPtObj = CATVPShow;
			CATVisGeomType GeomTypeOnPtObj = CATVPGlobalType;
			PropValue.SetShowAttr(CATNOShowAttr);
			rc = pPropONElem -> SetPropertiesAttr(PropValue,
				PropTypeOnPtObj,
				GeomTypeOnPtObj);
			pPropONElem ->Release();
			pPropONElem = NULL;
		}
	}
}

/**
* ���Ԫ����ʾ״̬
*/
bool CheckIsShow(CATIVisProperties_var spPropOnTreeNode)
{
	// 5/18  add
	bool IsShow = false;

	CATShowAttribut oShow ;
	if ( NULL_var != spPropOnTreeNode )
	{
		if ( SUCCEEDED(GetShow(spPropOnTreeNode,oShow,2)))
		{
			// model show flag
			if (oShow == CATShowAttr)
			{
				IsShow = true;
			}
		}
	}//--- 5/18 add

	return IsShow;
}

/**
* ȡ��Ԫ����ʾ��ʶ Show Flag
*/
HRESULT GetShow(CATIVisProperties_var spProp, CATShowAttribut &oShow ,int Mode )
{
	if ( spProp == NULL_var)
		return E_FAIL;
	CATVisPropertiesValues  MyPropertyOnFace;
	CATVisPropertyType PropTypeOnFace = CATVPShow;
	CATVisGeomType GeomTypeOnFace;
	if ( Mode == 1 )
		GeomTypeOnFace     = CATVPMesh;
	else
		GeomTypeOnFace     = CATVPGlobalType ;
	HRESULT rc = spProp->GetPropertiesAtt(MyPropertyOnFace,PropTypeOnFace,GeomTypeOnFace);
	if ( SUCCEEDED(rc) )
	{
		HRESULT HR = MyPropertyOnFace.GetShowAttr(oShow);
		if ( FAILED(HR))
			return E_FAIL;
	}
	return S_OK;
}

3��C�� C++ �ַ���ת��  �ֽ���
	string  str="�ͷ�������c#д�ģ��������c++";
	   send(str);
	public void send(msg)
	{
		string hexstr=StringToHexString(str)
		char[] chars= hexstr.ToCharArray();
		byte[] byteData = Encoding.Default.GetBytes(chars);  
		socket.write(byteData ,0,byteData.length);
	}
	//�ַ���תΪ16����
	public string StringToHexString(string message)
	{
		//����ָ�����뽫string����ֽ�����
		byte[] b = Encoding.UTF8.GetBytes(message);
		string result = string.Empty;
		for (int i = 0; i < b.Length; i++)
		{
			result += Convert.ToString(b[i], 16);
		}
		return result.ToUpper();
	}


4������exe�ļ�
	ShellExecute(0,(LPCWSTR)L"open",(LPCWSTR)L"D:\\Bin_x64\\SuperMapDemo.exe",(LPCWSTR)L"",(LPCWSTR)L"",SW_SHOWNORMAL);

	SHELLEXECUTEINFO ShellInfo;

		memset(&ShellInfo,0,sizeof(ShellInfo));
		ShellInfo.cbSize=sizeof(ShellInfo);
		ShellInfo.hwnd=NULL;
		ShellInfo.lpVerb=_T("open");
		//ShellInfo.lpFile=_T("..\\..\\..\\SuperMapDemo\\SuperMapDemo.exe");
		ShellInfo.lpFile=_T("E:\\supermap\\Bin_x64\\SuperMapDemo.exe");
		ShellInfo.lpParameters= name;
		ShellInfo.nShow=SW_HIDE;//SW_SHOWNORMAL
		ShellInfo.fMask=SEE_MASK_NOCLOSEPROCESS;
		BOOL bResult=ShellExecuteEx(&ShellInfo);
		if (!bResult)
		{
			return false;
		}

		�к� ���� ����  
		1 SW_HIDE ����������壬�������������塣 
		2 SW_MAXIMIZE ���ָ���Ĵ��塣  
		3 SW_MINIMIZE ��С��ָ���Ĵ��壬����˳�򼤻����ϲ�Ĵ��塣  
		4 SW_RESTORE �����ʾ���塣�������Ϊ��С��������󻯣�����ָ���ԭʼ��С��λ�á�Ӧ�ó��򵱻ָ�һ����С���Ĵ���ʱ��ָ����ǡ� 
		5 SW_SHOW �Ե�ǰ�Ĵ�С��λ�ü����ʾ���塣 
		6 SW_SHOWDEFAULT   
		7 SW_SHOWMAXIMIZED ��������ʾ���塣
		8 SW_SHOWMINIMIZED �����С����ʵ���塣 
		9 SW_SHOWMINNOACTIVE ��С�����壬�����伤��״̬�� 
		10 SW_SHOWNA �Ե�ǰ״̬��ʾ���壬�����伤��״̬��  
		11 SW_SHOWNOACTIVATE �Ե�ǰ�Ĵ�С��λ����ʾ���壬�������伤��״̬�� 
		12 SW_SHOWNORMAL �����ʾһ�����塣�������Ϊ��󻯻�����С��������ָ���ԭʼ�Ĵ�С��λ�á��������һ����ʾ��ʱ��Ӧ�ó����¼��ǡ�



5��������ģʽ����ļ���rootProduct
HRESULT GetCurrentDoc_TopProduct( CATIProduct_var & spTopProd)
{
//--------------------------------------------------------------------
// 1. Prologue 
//--------------------------------------------------------------------

  cout << endl << flush;
  cout << endl << flush;
  cout << "----------------------------------------------------------------" << endl << flush;
  cout << endl << flush;

  // --- Creating the Session:  A session must always be created in a batch
  char *sessionName = "CAA_EhiFilter_Session";
  CATSession *pSession = NULL;
  HRESULT rc = ::Create_Session(sessionName,pSession);
  if ((SUCCEEDED(rc)) && (NULL != pSession))
  {
    cout << "> session created : " << sessionName <<endl << flush;
  }
  else
  {
    cout << "ERROR in creating session" << sessionName << endl << flush;
    return 1;
  }
  
  // --- Opening an existing document 
  //     The input parameter to this sample program must contain 
  //     the entire path and name of the document that is to be opened.  
  
  CATDocument *pDoc = NULL;  // pDoc is a pointer to the document 

  cout << "> open document :"<< argv[1] << argv[2] << endl << flush;
  rc = CATDocumentServices::OpenDocument(CATUnicodeString(argv[1])+CATUnicodeString(argv[2]), pDoc);
  
  CATLockDocument(*pDoc);

  if (SUCCEEDED(rc) && (NULL != pDoc))
  {
    cout << "> document opened " << endl << flush;
  }
  else
  {
    cout << "ERROR in opening document" << endl << flush;
    return 2;
  }
  
  // --- Retrieving root product of the opened document 
  
  CATIProduct* piRootProduct = NULL; // piRootProduct is a handle to document root product  
  //  
  CATIDocRoots * piDocRoots = NULL;
  rc = pDoc->QueryInterface(IID_CATIDocRoots,(void**) &piDocRoots);
  if ( FAILED(rc) || (NULL==piDocRoots) ) 
  {
	cout << "ERROR : Failed to query CATIDocRoots" << endl;
	return 3;
  }
  CATListValCATBaseUnknown_var* pListRootProduct = piDocRoots->GiveDocRoots();
  piDocRoots->Release();
  piDocRoots=NULL;
  
  if ( pListRootProduct && pListRootProduct->Size() )
  {  
    CATBaseUnknown_var hUnk = (*pListRootProduct)[1];

    if (NULL_var != hUnk) 
		rc = hUnk->QueryInterface(IID_CATIProduct,(void**) &piRootProduct );
    if (pListRootProduct) 
		delete pListRootProduct;
		pListRootProduct = NULL;
    //
    if  (SUCCEEDED(rc) && (NULL != piRootProduct))
    {
		cout << "> root product found in document " << endl << flush;
		spTopProd = piProductOnRoot;
		CATUnicodeString partNumber = piProductOnRoot->GetPartNumber();
		cout << "Working with '" << partNumber.ConvertToChar() << "'" << endl;
		return S_OK;
	}
    else
    {
      cout << "ERROR : Root product not found in document " << endl << flush;
      return 3;
    }
  }
  
//--------------------------------------------------------------------
	
	//������ͼ
	CATInit *piInitOnDoc = NULL;
	rc = pDoc -> QueryInterface (IID_CATInit,(void**) &piInitOnDoc);
	if(SUCCEEDED(rc) && NULL != piInitOnDoc)
	{
		//��ȡContainer
		const CATIdent idCATIContainer = "CATIPrtContainer";
		CATIPrtContainer *piRootContainer = NULL;
		piRootContainer = (CATIPrtContainer*)
			piInitOnDoc -> GetRootContainer(idCATIContainer);
		if(NULL != piRootContainer)
		{
			CATIPrtPart_var spPart = piRootContainer->GetPart();
			CATIBasicTool_var spTool= spPart->GetCurrentTool();

			CATIDescendants_var spDesTool = spPart;
			CATListValCATISpecObject_var  oLst ;
			spDesTool->GetAllChildren("CATIMechanicalTool",oLst);
			CATISpecObject_var spMainBody = oLst[1];
			CATIAlias_var spAlias = spMainBody;
			cout << spAlias->GetAlias() << endl << flush;

			CATISketchFactory_var spSketchFactory(piRootContainer);
			if(NULL_var != spSketchFactory)
			{
				CATISpecObject_var spSketchSpec=spSketchFactory->CreateSketch();
				CATISketch_var spSketch=spSketchSpec;
				if(NULL_var != spSketch)
				{
					spSketch->OpenEdition();
					CATI2DWFFactory_var sketch2DFactory(spSketch);
					if(NULL_var != sketch2DFactory)
					{
						double Origin[2]={0.,0.};
						double Radius=10;
						CATISpecObject_var spSpecCircle=
							sketch2DFactory->CreateCircle(Origin,Radius);
						if(NULL_var != spSpecCircle)
						{
							cout<<"��ͼ�д���Բ�ɹ���"<<endl;	
						}
						spSketch->CloseEdition();

						spPart->SetCurrentFeature(spMainBody);


						//����͹̨
						CATIPrtFactory * piPrtFact=NULL;
						rc=piRootContainer->QueryInterface(IID_CATIPrtFactory,
							(void **)&piPrtFact);
						if(SUCCEEDED(rc) && NULL != piPrtFact)
						{
							CATISpecObject_var spPad=piPrtFact->CreatePad(spSketch);
							if(NULL_var != spPad)
							{
								CATIPad_var spPadPad=spPad;
								if(NULL_var != spPadPad)
								{
									spPadPad->ModifyEndType(catOffsetLimit);
									spPadPad->ModifyEndOffset(20.);
								}

								spPad->Update();
								cout<<"����͹̨�ɹ���"<<endl;
							}
							piPrtFact->Release();
							piPrtFact=NULL;

							CATISpecObject_var spPart = piRootContainer->GetPart();
							spPart->Update();
						}
					}
				}
			}

			CATISpecObject_var spParentForTool = spMainBody;
			CATIMechanicalRootFactory_var spMechRoot = piRootContainer;
			CATISpecObject_var spSpecGS1 = NULL_var;
			rc = spMechRoot -> CreateGeometricalSet("��������ͼ�μ�1",spParentForTool,spSpecGS1);
		}

		piInitOnDoc->Release();
		piInitOnDoc=NULL;
	}

//-------------------------------------------------------------------------
// Callback on DiaOK of _BITCreateAssemSndDlg
//-------------------------------------------------------------------------
#include"iostream.h"
#include"fstream.h"
#include "CATNotification.h"
void BITCreateAssemSndDlg::OnBITCreateAssemSndDlgDiaOKNotification(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{	
	_OpenNotify = new CATDlgNotify(this, "", CATDlgNfyOKCancel);//����ѯ����Ϣ��
	_OpenNotify->SetText("������Ϣ��");
	_OpenNotify->SetVisibility(CATDlgShow);

	pDlgFile = new CATDlgFile(this,"����",CATDlgFileSave);//�����ļ�ѡ���
	pDlgFile->SetVisibility(CATDlgShow);	
	CATUnicodeString nameExtension = CATUnicodeString("txt files");//�����ļ���ʽΪtxt
	CATString filterExtension = CATString("*.txt");
	pDlgFile->SetFilterStrings(&nameExtension, &filterExtension, 1);
	pDlgFile->SetFileName("��Ϣ��¼");//�����ļ�Ĭ������Ϊ��Ϣ��¼
	int iTypeOfInput = 0;
	//����ļ�ѡ���ȷ����ť�¼��ص����� ActOnOK
	AddAnalyseNotificationCB (pDlgFile, 
		pDlgFile->GetDiaOKNotification(),
		(CATCommandMethod)&BITCreateAssemSndDlg::ActOnOK,
		&iTypeOfInput);
}

//�¼��ص����� ActOnOK��ʵ��
void BITCreateAssemSndDlg::ActOnOK(CATCommand * cmd, CATNotification* evt , CATCommandClientData data)
{
	CATUnicodeString fileName;
	pDlgFile->GetSelection(fileName);//��ȡѡ���·��
	_OpenNotify = new CATDlgNotify(this, "", CATDlgNfyOK);//ѡ���·����ʾ��
	_OpenNotify->SetText("�ļ��������浽:"+fileName);
	_OpenNotify->SetVisibility(CATDlgShow);

	fileName=fileName+".txt";
	const char *filepath=fileName.ConvertToChar();
	ofstream outfile(filepath,ios::out|ios::trunc);//��c++������ļ�
	if(!outfile)	 
	{
		_OpenNotify = new CATDlgNotify(this, "", CATDlgNfyError);
		_OpenNotify->SetText("�򿪳���");
		_OpenNotify->SetVisibility(CATDlgShow);
	}
	outfile<<"����  "<<"�Ա�  "<<"����  "<<"ϲ��ѧ��	  "<<endl;
	CATUnicodeString	 name,gender,age,subject;
	int ColumnNum=_MultiListInformation->GetLineCount();
	for(int i=0;i<ColumnNum;i++)
	{
		//��ȡMultiListInformation�е���Ϣ
		_MultiListInformation->GetColumnItem(0, name,i);
		_MultiListInformation->GetColumnItem(1, gender,i);
		_MultiListInformation->GetColumnItem(3, age,i);
		_MultiListInformation->GetColumnItem(2, subject,i);
		//�˴���Ҫ�����ַ����������ʽ��ʹ��txt��ʽ����
		name.Resize(6,' ',0);
		gender.Resize(4,' ',0);
		age.Resize(4,' ',0);
		outfile<<name<<" "<<gender<<" "<<age<<" "<<subject<<" "<<endl;
	}
	pDlgFile->RequestDelayedDestruction();
	pDlgFile=NULL;
}



void BITCreateAssemSndDlg::OnMultiListInformationListSelectNotification(CATCommand* cmd, CATNotification* evt, CATCommandClientData data)
{
	int selectLine[1];
	int selectNumb = _MultiListInformation->GetSelect(selectLine,1);
	CATUnicodeString	 name,gender,age,subject;
	_MultiListInformation->GetColumnItem(0, name,selectLine[0]);
	_MultiListInformation->GetColumnItem(1, gender,selectLine[0]);
	_MultiListInformation->GetColumnItem(3, age,selectLine[0]);
	_MultiListInformation->GetColumnItem(2, subject,selectLine[0]);
	_EditorName->SetText(name);//Editorֵ����
	if(gender=="��") {_RadioButtonMale->SetState(CATDlgCheck);_RadioButtonFemale->SetState(CATDlgUncheck);}//RadioButton״̬����
	if(gender=="Ů") {_RadioButtonMale->SetState(CATDlgUncheck);_RadioButtonFemale->SetState(CATDlgCheck);}
	int ageNumb;
	age.ConvertToNum(&ageNumb,"%d");//�ַ���ת��Ϊ����
	_ComboAge->SetSelect(ageNumb-20);
	if(-1==subject.SearchSubString("֪ʶ����"))//�ַ�������
		_CheckButtonKnowledge->SetState(CATDlgUncheck);//CheckButton״̬����
	else _CheckButtonKnowledge->SetState(CATDlgCheck);
	if(-1==subject.SearchSubString("������켯��"))
		_CheckButtonDesign->SetState(CATDlgUncheck);
	else _CheckButtonDesign->SetState(CATDlgCheck);
	if(-1==subject.SearchSubString("��ά�������"))
		_CheckButton3D->SetState(CATDlgUncheck);
	else _CheckButton3D->SetState(CATDlgCheck);
}