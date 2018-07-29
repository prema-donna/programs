using System;

namespace Concatenation {
	class Name {
		private string FullName(string a, string b, string c){
			string full_name_with_space = a +" "+ b +" "+ c;
			return full_name_with_space;
		}
		private string AlphaNumericID(string word, int id){
			string ID = word+id.ToString();
			return ID;
		}
		private int ASCIIsum(string a, string b, string c){
			int sum = 0;
			for (int i= 0; i<a.Length; i++){
				char letter= a[i];
				sum += Convert.ToInt32(letter);
			}
			for (int i= 0; i<b.Length; i++){
				char letter= b[i];
				sum += Convert.ToInt32(letter);
			}
			for (int i= 0; i<c.Length; i++){
				char letter= c[i];
				sum += Convert.ToInt32(letter);
			}
			return sum;
		}
		static void Main(string[] args){
			string first_name = "Akila";
			string middle_name = "Wirane";
			string last_name = "Premachandra";
			string word = "AWP";
			Name n = new Name();
			
			string my_name = n.FullName(first_name,middle_name,last_name);
			Console.WriteLine("My name is {0}", my_name);
			
			int ASCII = n.ASCIIsum(first_name,middle_name,last_name);
			Console.WriteLine("ASCII sum of name = {0}", ASCII);
			
			string aID = n.AlphaNumericID(word,ASCII);
			Console.WriteLine("ID: {0}", aID);
			
		}
	}
}
			
