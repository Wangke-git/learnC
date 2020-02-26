bool canConstruct(char * ransomNote, char * magazine) {
	int mark1[26] = { 0 }, mark2[26] = { 0 };//ģ��HASH
	char mark[26];
	int i, j, length1 = strlen(ransomNote), length2 = strlen(magazine), length = 0;
	if (length1 == 0)
		return true;
	if (length1 > length2)
		return false;
	for (i = 0, j = 0; i < length1 || j < length2; i++, j++)
	{
		if (i < length1)//��¼��һ���ַ����е�Ԫ�صĸ���
		{
			mark1[ransomNote[i] - 'a']++;
			if (mark1[ransomNote[i] - 'a'] == 1)
				mark[length++] = ransomNote[i];
		}
		if (j < length2)
			mark2[magazine[j] - 'a']++;//��¼�ڶ����ַ����е�Ԫ�صĸ���
	}
	for (i = 0; i < length; i++)
	{
		if (mark1[mark[i] - 'a'] > mark2[mark[i] - 'a'])
			return false;
	}
	return true;
}

