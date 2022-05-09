/*
Trie:

	It is a tree data structure used for storing collections of strings

	If 2 strings have a common prefix, then they will have a same ancestor in this tree

	So, in essence if we have thousands of strings, or hundreds of thousands of strings, then we can use trie
		to store all the strings and then it's really easy to search if a string exist in this
		collections of strings or not

	For example, trie is an ideal data structure for storing our dictionary

		Trie can also be used to do prefix based search and we can sort the strings lexicographical in the trie

	-------

	Another alternative to Trie is to use a HashTable

		However, with a HashTable we cannot do a prefix based search and also a regular HashTable takes more
			space than trie

-------

Insertion into Trie:

	Trie is a tree data structure and this tree is made up of collections of trie node

	Every Trie node has two main components:

		A Map where the 'key' is the character and the 'value' is the trie node

			Map<Character, TrieNode> children;

		2nd is the boolean variable let's say 'endOfWord'
			indicating that the character representing this trie node is an end of word or not

			if our character set consists of just lower cases or just upper cases, then we could replace
				this map with an array of size 26

	-------

	Suppose I want to insert the following words into my trie data structure:
		abc
		abgl
		cdf
		abcd
		lmn

		-------

						           Root

					 	 /          |          \
					 	a    					c
					 							False
					  False         l             \
		        		            False          d
					                   \           False
					 	         		m            \
					 /                 False          f
				    b                    \           False
				  False           	      n             \
				   /   \                  False          True
				  c                	        \
				  		g
				  	  False                 True
			False        \
		      /           l
		     d           False
		    False          /
		    /            True
		  True

    Insertion into the trie:

    	Initially our trie is a root and root has an empty map, and boolean end of word is false

    	Next we want to insert the first word 'abcd' into our trie

    		Firstly we check if 'a' is present in the map of this root or not
    			in this particular case, map of the root was empty

    			hence we will create a new trie node whose end of word is false, and we will put 'a' into the root map,
    				and for the value we will put the reference of the newly created trie node

			We increment our traversing pointer to 'b' and we move to our newly created  trie node
				we will check here, if 'b' present in the map of this trie node

				since the node was newly created, and 'b' is not present so we will create another trie node
					put the value false, and finally we will put 'b' into the map of the previously created trie node
					and for the value we will put the reference of this newly created trie node

			Similarly we follow the entire procedure
				Whenever any node (more specifically a character) doesn't present, we firstly add a new trie node and set it's endOfWord to false
					and add that character to the map of the previous node, and as a value we add the reference to the newly created node

	-------

	In the trie, if two words has the same prefix they share the common ancestor

	-------

	Time complexity for inserting into trie:

		if the average length of the word is 'l' and total number of words are 'm'

			Then the time complexity is O(l x m)

-------

Search into trie:

	There are two kinds of searches

		a. prefix based search, where we are checking if there is at-least one word
		which starts with a given prefix or not

		b. whole word search, where we are checking if the entire word exists or not

-------

Example 1:

	prefix based search

		Suppose we have two words
			ab, lo

			and we want to check if there is at-least one word that starts with a given prefix or not

			-------

			We starts with root, and we will check if the Map at the root contains a or not
				in this particular contain it does contain
					so we will jump to that trie node and we will reach node containing 'b'

					and in this trie node we will check if the map here contains 'b' or not

						in this particular it does contain 'b' so we will return true

				It means that there is at least one word, which does starts with ab, there is no reason to look more

				Similarly we will perform the operations for the next prefix 'lo'
					"lo" will return false, because while following the root node that contains "l"
						there is no other trie node whose map contain the character 'o'

	whole world search:

		for the whole word search we have to follow the entire path following the root trie node and
			in the end check if the trie node's endOfWord value contains True, only then we will return true

Time complexity for searching a node in a trie:

	If the length of the word is 'l', then the time to search will be O(l)

-------

Delete in a trie:

	a. Deleting an entire word, or

	b. Delete all the words which starts with the given prefix

	-------

	Example 1.

		Suppose we are trying to delete the word "abc"

			We starts at root, and 'a' exists in the map of the root, so here we will follow the link
				we will reach the next trie node, and 'b' exists in this trie node, so we will follow the link

				in the next node 'c' exists, so we will follow the link and reach the next trie node which is 'd'

				at this point we are at node 'd' and we want to delete "abc", we cannot delete the entire node because
					if we just remove this node also, in that case we will lose the ability for search a word like "abcd"

					since this map at this current trie node is not empty, therefore we can't get rid of this node
						hence all we can do is to change the value of endOfWord for this word to "false"

		now suppose we are trying to delete the word "abgl"

			Now after following the above described procedure we will in the end reach to the end node
				whose map is empty and the endOfWord variable for this map is True

				so we can safely remove this word,

				next we move further up, since the next node of this current trie node has already been deleted so we can also
					safely make it's map empty and delete this node

				we will move again one level up, and delete the node 'g' from the map of this current node
					now we cannot delete this entire node, because this node has one another node in its map

Time Complexity for deleting the words:

	If average length is 'l' and the number of words are n
		then O(l * n) will be the time complexity

*/

public class Trie {

	private class TrieNode {
		Map<Character, TrieNode> childrenMap;
		boolean endOfWord;

		public TrieNode {
			childrenMap = new HashMap<>();
			endOfWord = false;
		}
	}

	private final TrieNode root;

	public Trie {
		root = new TrieNode();
	}

	// Iterative implementation of insert into trie
	public void insert(String word) {
		TrieNode current = root;
		for (int i = 0; i < word.length; ++i) {
			char ch = word.charAt(i);
			TrieNode node = current.childrenMap.get(ch);
			if (node == null) {
				node = new TrieNode();
				current.childrenMap.put(ch, node);
			}
			current = node;
		}
		current.endOfWord = true;
	}

	// Recursive implementation of insert into trie
	public void insertRecursive(String word) {
		insertRecursive(root, word, 0);
	}

	private void insertRecursive(TrieNode current, String word, int index) {
		if (index == word.length()) {
			current.endOfWord = true;
			return;
		}
		char ch = word.charAt(index);
		TrieNode node = current.childrenMap.get(ch);

		// if the node does not exists in the map then create one and put it into the map
		if (node == null) {
			node = new TrieNode();
			current.childrenMap.put(ch, node);
		}
		insertRecursive(node, word, index + 1);
	}

	// Iterative implementation of search into trie
	public boolean search(String word) {
		TreeNode current = root;
		for (int i = 0; i < word.length; ++i) {
			char ch = word.charAt(i);
			TrieNode node = current.childrenMap.get(ch);
			// if node does not exist for a given char return false
			if (node == null) {
				return false;
			}
			current = node;
		}
		// return endOfWord's value for the current
		return current.endOfWord;
	}

	//Recursive implementation of search into trie
	public boolean searchRecursive(String word) {
		return searchRecursive(root, word, 0);
	}

	private boolean searchRecursive(TrieNode current, String word, int index) {
		if (index == word.length()) {
			//return the value of the current's endOfWord
			return current.endOfWord;
		}
		char ch = word.charAt(index);
		TrieNode node = current.childrenMap.get(ch);
		// if the node doesn't exist for given char then return false
		if (node == null) {
			return false;
		}
		return searchRecursive(node, word, index + 1);
	}

	//Deleting a word from trie
	public void delete(String word) {
		delete(root, word, 0);
	}

	//Function that will return true if the parent should delete the mapping
	private boolean delete(TrieNode current, String word, int index) {
		if (index == word.length()) {
			//when end of the word is reached only delete if the current.endOfWord is true
			if (!current.endOfWord) {
				return false;
			}
			current.endOfWord = false;
			//if current has no other mapping then return true
			return current.children.size() == 0;
		}
		char ch = word.charAt(index);
		TrieNode node =  current.childrenMap.get(ch);
		if (node == null) {
			return false;
		}
		boolean shouldDeleteCurrentNode = delete(node, word, index + 1);

		//if true is returned then delete the mapping of character and trieNode reference from the map
		if (shouldDeleteCurrentNode) {
			current.childrenMap.remove(ch);
			//return true if no mapping are left in the map
			return current.childrenMap.size() == 0;
		}
		return false;
	}
}
