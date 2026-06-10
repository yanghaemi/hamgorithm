import java.util.*;

class UserSolution
{

	class Node{
		// int mId;
		int mTeam;
		int mScore;
		Node pre;
		Node next;

		Node(int mTeam, int mScore){
			this.mTeam = mTeam;
			this.mScore = mScore;
		}
	}

	Node[] arr;

	Node[][] head;
	Node[][] tail;

	public void init()
	{
		arr = new Node[100_001];
		// Arrays.fill(arr, new Node(-1, -1));
		for(int i = 0; i < arr.length; i++) {
        	arr[i] = new Node(-1, -1);
    	}
		
		for(int i=0;i<6;i++){
			teamList[i] = new ArrayList<>();
		}
	}
	
	public void hire(int mID, int mTeam, int mScore)
	{
		arr[mID].mTeam = mTeam;
		arr[mID].mScore = mScore;
		teamList[mTeam].add(mID);
	}
	
	public void fire(int mID)
	{
		// int tempTeam = arr[mID].mTeam;
		// teamList[tempTeam].remove(teamList[tempTeam].indexOf(mID));
		
		arr[mID].mTeam = -1;
		arr[mID].mScore = -1;
	}

	public void updateSoldier(int mID, int mScore)
	{
		arr[mID].mScore = mScore;
	}

	public void updateTeam(int mTeam, int mChangeScore)
	{
		for(int mID : teamList[mTeam]){
			int tempScore = arr[mID].mScore;
			if(arr[mID].mTeam != mTeam) continue;
			if(tempScore + mChangeScore > 5) tempScore = 5;
			else if(tempScore + mChangeScore < 1) tempScore = 1;
			else tempScore += mChangeScore;
			arr[mID].mScore = tempScore;
		}
	}
	
	public int bestSoldier(int mTeam)
	{
		int maximum = 0;
		int maxID = 0;
		for(int mID : teamList[mTeam]){
			if(arr[mID].mTeam != mTeam) continue;
			if(maximum < arr[mID].mScore){
				maximum = arr[mID].mScore;
				maxID = mID;
			} else if(maximum == arr[mID].mScore && maxID < mID){
				maximum = arr[mID].mScore;
				maxID = mID;
			}
		}
		// System.out.println("========bestSoldier: "+maxID);
		return maxID;
	}
}