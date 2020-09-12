#include "Battle.h"
#include <fstream>
#include "Enemies\paver.h"
#include "Enemies\fighter.h"
#include "Enemies\Sighter.h"
#include "GUI\GUI.h"
#include "Castle\Castle.h"

Battle::Battle() // constructor of the battle 
{
	EnemyCount = 0; //set the number of enemies to 0
	kcount=0;
	TotalFD=0;
	TotalKD=0;
	totalcount=0;
}

void Battle::AddEnemy(Enemy* Ptr)
{
	if (EnemyCount < MaxEnemyCount) 
		BEnemiesForDraw[EnemyCount++] = Ptr;

	// Note that this function doesn't allocate any enemy objects
	// It only makes the first free pointer in the array
	// points to what is pointed to by the passed pointer Ptr
}

void Battle::DrawEnemies(GUI * pGUI)
{
	pGUI->DrawEnemies(BEnemiesForDraw, EnemyCount);
}


Castle * Battle::GetCastle() // return the pointer on the castle
{
	return &BCastle;
}
void Battle ::read(GUI*pGUI)// function to read the input  file that contains the data of enemies
{
	Clear();
	string filename;  // the name od input file
	pGUI-> PrintMessage("please enter the name of file");// print message on the status bar
	filename=pGUI ->GetString();  // get the name of the file
	ifstream inputfile; 
	inputfile.open(filename+".txt");

	while(!inputfile.is_open()) // if the input file not open means if the file name not existed
	{
		pGUI->PrintMessage("file is not exist , please enter the name of file ");// he file print message the file name is not exist and ask th user to enter the right name of the file
		filename=pGUI ->GetString();
		inputfile.open(filename+".txt");
	}

	int a,b; //a is the starting health of all towers // b is the maximum number of enemies a tower can attack at any time step

	double c,d,f,numberofenem; // the constants of equation “Priority (Enemy)”
	double n,type,timestep,h,firepow,reload;// n is time step // type is type of enemy which is paver/ fighter/shielde//
	// h is health of the enemy // firpow is the fierpower of the enemy // reload is the reloaded time of enemy



	char region; // region of the enemy
	bool exit =true; 
	inputfile >> a; // read  the starting health of all towers 
	BCastle.SetTowersHealth(a); 
	inputfile>>numberofenem>>b;
	BCastle.SetTowersPower(b);
	BCastle.SetTowersMaxNum(numberofenem);
	inputfile>>c>>d>>f;
	Sfighter::setconst(c,d,f);
	n=0;
	int count=0;
	inactive.clearlist();
	while(exit)
	{
		inputfile>> n>> type>>timestep>> h>>firepow>>reload;
		inputfile>>region; // read the details and information of enemies
		count++;
		if(n==-1)// if the timestep =-1 so the input file is ended
		{
			exit=false; 
		}
		else
		{
			Enemy* e=NULL;
			if ( type == 0)
			{
				e =new paver ; // creat a paver enemy 
			}
			else if (type == 2)
			{
				e =new Sfighter;// creat a shielded fighter enemy 
			}
			else if ( type == 1)
			{
				e =new fighter ;// creat a fighter enemy 
			}
			switch (region) // set the enemy in its region 
			{
			case('A'):e->setregion('A');// set the regionto A
				break;
			case('B'):e->setregion('B'); // set the regionto B
				break;
			case('D'):e->setregion('D');// set the regionto D
				break;
			case('C'):e->setregion('C');// set the regionto C
				break;
			}
			e->setID(n);
			e->setype(type);
			e->setime(timestep);
			e->sethealth(h);
			e->setfire(firepow);
			e->setRLD(reload);
			inactive.enqueue(e);
			totalcount++;
		}
	}
}
void Battle ::toactive(int i)
{
	Enemy*e;
	bool exit=true;
	while (exit && !(inactive.getfront()==NULL))
	{
		e=inactive.getfront();
		if(e->getime()==i)
		{
			e=inactive.dequeue();
			BCastle.setenemy(e);
			AddEnemy(e);
		}
		else
			exit=false;
	}
}

void Battle ::simulation(GUI*pg,actions action)
{
	Point p;
	if(inactive.getfront()==NULL)
	{
		pg->PrintMessage("load file first then try again :)");
	}
	else
	{
		ofstream outputfile; 
		outputfile.open("filename.txt");
		outputfile<< "KTS"<<" "<<"S"<<" "<<" FD"<<" "<<" KD"<<" "<<" LT"<<endl;
		int timestep=1;
		toactive(timestep);
		while((EnemyCount !=0||inactive.getfront()!=NULL)&& (!isloss()))
		{

			toactive(timestep);
			BCastle.ShiftTowers();
			BCastle.attackenemis(timestep);
			BCastle.checkkilled(timestep);
			deletearr();
			printkilled(outputfile);
			BCastle.deletekilled();
			killed.clearlist();
			BCastle.move();
			BCastle.attacktower();
			switch (action)
			{
			case automode:
				Sleep(1000);
				pg->ClearStatusBar();
				pg->ClearBattleArea();
				pg->DrawCastle();
				DrawEnemies(pg);
				break;
			case interactivemode:
				pg->GetPointClicked(p);
				pg->ClearStatusBar();
				pg->ClearBattleArea();
				pg->DrawCastle();
				DrawEnemies(pg);
				break;
			}
			
			pg->PrintMessage("killed count"+ to_string(kcount),0,0);
			pg->PrintMessage("Enemy count"+ to_string(EnemyCount),0,1);
			for(int i=0;i<4;i++)
			{
				pg->PrintMessage(to_string(int(BCastle.GetTowershealth(i)))+"  ",1,i);
			}
			/*PlaySoundA("F:\projects\final phase 1 project\final phase 1 project\FILENAME\Kehlani - Gangsta - MP3 320.mp3", NULL, SND_FILENAME);
			PlaySoundA(TEXT("F:\projects\final phase 1 project\final phase 1 project\FILENAME\Kehlani - Gangsta - MP3 320.mp3"), NULL, SND_SYNC);*/
			timestep++;
		}
		printall(outputfile);
		pg->ClearStatusBar();
		pg->ClearBattleArea();
		pg->DrawCastle();
		pg->PrintMessage("Game is over :)");
	}
}

void Battle ::deletearr()
{
	Enemy *e;
	for (int i = 0; i < EnemyCount; i++)
	{
		if((BEnemiesForDraw[i]->gethealth()) == 0)
		{

			e=BEnemiesForDraw[i];
			BEnemiesForDraw[i]=BEnemiesForDraw[EnemyCount-1];
			BEnemiesForDraw[EnemyCount-1]=NULL;
			kcount++;
			EnemyCount--;
			i--;
			killed.append(e);
		}
	}
}

void Battle ::printkilled(ofstream&outputfile)
{
	
	Enemy* e;
	LinkedList<Enemy>K;
	int count=0;
	for(int k=0;k<NoOfRegions;k++)
	{
		for (int i=1;i<=BCastle.getkcountenemy(k);i++)
		{
			e=BCastle.getkilled(k).getvalue(i);
			K.append(e);
			count++;
		}
	}
	killed.MergeSort();
	
	for (int i=1;i<=count;i++)
		{
			outputfile<<killed.getvalue(i)->getkilledtime()<<" "<<killed.getvalue(i)->getID()<<" "<<killed.getvalue(i)->getFD()<<" "<<killed.getvalue(i)->getkilledtime()<<" "<<killed.getvalue(i)->getLT()<<endl;
			TotalFD=TotalFD+(killed.getvalue(i)->getFD());
			TotalKD=TotalKD+(killed.getvalue(i)->getKD());
		}
	
}
void Battle ::print (GUI*pGUI)// TO print Total number of active enemies and information of each one of them.
{
	for (int i=0;i<NoOfRegions;i++)//loop on regions
	{
		string a; // region 
		if(i==0)
			a="A";
		else if(i==1)
			a="B";
		else if(i==2)
			a="C";
		else
			a="D";

		pGUI->PrintMessage("tower "+a,0,i);
		pGUI->PrintMessage("health  NumEnemies  firepow",1,i);
		pGUI->PrintMessage(to_string(int(BCastle.GetTowershealth(i)))+" "+to_string(int(BCastle.GetTowersmaximum(i)))+" "+to_string(int(BCastle.GetTowerspower(i))),2,i);

		pGUI->PrintMessage("active enemies : "+to_string(BCastle.getfcountenemy(i)+BCastle.getscountenemy(i)),3,i);
		//print the number of shielded fighters and fighters enemies
		pGUI->PrintMessage("ID Health typ TS RLD POW ",4,i);
		int l;
		BCastle.getSF(i).beginref();
		for(l=1;l<=BCastle.getscountenemy(i);l++)//loop on number of shielde fighters
		{
			pGUI->PrintMessage(to_string(int( BCastle.getSF(i).getref()->getID()))+" "+to_string(int( BCastle.getSF(i).getref()->gethealth()))+" "+to_string( int(BCastle.getSF(i).getref()->getype()))+" "+to_string(int( BCastle.getSF(i).getref()->getime()))+" "+to_string(int( BCastle.getSF(i).getref()->getRLD()))+" "+to_string(int( BCastle.getSF(i).getref()->getfire()))+" ",4+l,i);
			// print the informtion of shielded fighter on the status bar

			BCastle.getSF(i).advance(); 
		}
		int c=3+l;
		int k;
		BCastle.getF(i).beginref();
		for( k=1;k<=BCastle.getfcountenemy(i);k++)//loop on number of enemy fighters
		{
			pGUI->PrintMessage(to_string(int( BCastle.getF(i).getref()->getID()))+" "+to_string(int( BCastle.getF(i).getref()->gethealth()))+" "+to_string(int( BCastle.getF(i).getref()->getype()))+" "+to_string(int( BCastle.getF(i).getref()->getime()))+" "+to_string(int( BCastle.getF(i).getref()->getRLD()))+" "+to_string(int( BCastle.getF(i).getref()->getfire()))+" ",c+k,i);
			// print the informtion of shielded fighter on the status bar
			BCastle.getF(i).advance();
		}
		k=k+c;
		pGUI->PrintMessage("killed : "+to_string(BCastle.gettotkillenemy(i)),k,i);


	}
}
void Battle::Clear ()
{
	for (int i = 0 ; i<300;i++)
		BEnemiesForDraw[i]= NULL;
	EnemyCount=0;
	kcount=0;
}
bool Battle ::isloss()
{
	int count=0 ;
	
	for (int i=0;i<NoOfRegions;i++)
		{
			if (BCastle.GetTowershealth(i)==0)
			{
				count ++;
			}	
	}
	if(count ==4)
	{
		return true ;
	}
	else return false;

}
void Battle::printall(ofstream&outputfile)
{
		outputfile<<"T1_Total_Damage" <<" "<<"T2_Total_Damage" <<" "<<"T3_Total_Damage" <<" "<<"T4_Total_Damage" <<endl;
		for (int i=0;i<NoOfRegions;i++)
		{
			outputfile<<BCastle.GetTowersdamage(i)<<" ";
		}
		outputfile <<endl;
		outputfile<<"R1_Unpaved_Dist" <<" "<<"R2_Unpaved_Dist" <<" "<<"R3_Unpaved_Dist" <<" "<<"R4_Unpaved_Dist" <<endl;
		for (int i=0;i<NoOfRegions;i++)
		{
			outputfile<<BCastle.getunpaved(i)<<" ";
		}
		outputfile <<endl;
		int totalenemies=0;
		for(int i=0;i<NoOfRegions;i++)
			{
				totalenemies=totalenemies+(BCastle.gettotkillenemy(i));
			}
		double AvgFD,AvgKD;
		AvgFD=(TotalFD/totalenemies);
		AvgKD=(TotalKD/totalenemies);
		if(!isloss())
		{
			outputfile<<"game is WIN"<<endl;
			outputfile<<"Total enemies = "<<totalenemies;
			outputfile<<"Average First-Shot Delay = "<<AvgFD<<endl;
			outputfile<<"Average Kill Delay = "<<AvgKD<<endl;
		}
		else
		{
		
			outputfile<<"game is LOSS"<<endl;
			outputfile<<"Number of killed enemies = "<<totalenemies<<endl;
			outputfile<<"Number of alive enemies"<<(totalcount-totalenemies)<<endl;
			outputfile<<"Average First-Shot Delay of killed enemies = "<<AvgFD<<endl;
			outputfile<<"Average Kill Delay = "<<AvgKD<<endl;
			
		}
	
}
