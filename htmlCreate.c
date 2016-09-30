void createFile(char *html){

	FILE *fp;
	fp = fopen("index.html", "w");
	
	fprintf(fp, "%s", html);

	fclose(fp);

}
