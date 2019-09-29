#include<stdio.h>
#include<math.h>


int main(int argc, char *argv[])
{

		FILE* file = fopen(argv[1], "rb");
		if (!file)
		{
			printf("file not found");
			return 0;
		}
				int32_t buff[1];
				buff[0] = 0;
				int32_t hash = 0;
	
					fseek(file, 0, SEEK_END);
					int fileSize = ftell(file);
					int curentPos = 0;
					fseek(file, 0, SEEK_SET);

					while (curentPos < fileSize - 4)
					{
						fseek(file, curentPos, SEEK_SET);
						hash += buff[0];

						fread(buff, sizeof(int32_t), 1, file);
						//printf("%d\t%d\t%d\t%d\t%d\n", hash, buff[0], ftell(file), curentPos, fileSize);

						curentPos += 4;
					}
					printf("Finaly HASH: %d", abs(hash));
					return 0;
	
			//if (argv[2] == "crc32")
			//{
			//	printf("Nothing, sorry");
			//}
			//if (argv[2] != "crc32" && argv[2] != "sum32")
			//{
			//	printf("wrong mod");
			//}

			fclose(file);
		
		return 0;
}
