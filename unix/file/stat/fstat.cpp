#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COL_MODE 0x0001
#define COL_UID  0x0002
#define COL_GID  0x0004

// 所列列集合
static int sAllColSet[] =
{
	COL_MODE, COL_UID, COL_GID,
};


// 文件属性打印函数
struct ColConfig;
void printFileMode(const char *pathname, const ColConfig *cfg);

// 列配置
typedef void (*FuncPrint)(const char *pathname, const ColConfig *colCfg);
struct ColConfig
{
	int colKey;
	const char *colName;
	int colWidth;
	FuncPrint printFunc;

	ColConfig()
	{
		colKey = 0;
		colName = "";
		colWidth = 10;
		printFunc = NULL;
	}

	ColConfig(int key, const char *name, int width, FuncPrint func = NULL)
			:colKey(key), colName(name), colWidth(width), printFunc(func)
	{
	}
};

static ColConfig sColConfigs[] =
{
	{COL_MODE, "mode", 10, printFileMode},
	{COL_UID, "uid", 20},
	{COL_GID, "guid", 20},
};

static const ColConfig* getColConfig(int col)
{
	static int colCnt = sizeof(sColConfigs) / sizeof(ColConfig);
	for (int i = 0; i < colCnt; ++i)
	{
		if (col == sColConfigs[i].colKey)
		{
			return &sColConfigs[i];
		}
	}

	return NULL;
}


static int gColMode = COL_MODE;

int main(int argc, char *argv[])
{
	int begFileIdx = 1;
	if (argc > 1 && argv[1] != NULL)
	{
		if (strlen(argv[1]) > 0 && argv[1][0] == '-')
		{
			begFileIdx = 2;
			int n = strlen(argv[1]);
			for (int i = 1; i < n; ++i)
			{
				switch (argv[1][i])
				{
				case 'l':
					gColMode |= COL_MODE;
					break;
				case 'u':
					gColMode |= COL_UID;
					break;
				case 'g':
					gColMode |= COL_GID;
					break;
				}
			}
		}
	}

	// 打印列名
	static const int sColSize = sizeof(sAllColSet) / sizeof(int);
	printf("%*s", -20, "file");
	for (int i = 0; i < sColSize; ++i)
	{
		const ColConfig *cfg = getColConfig(sAllColSet[i]);
		if (cfg && (cfg->colKey & gColMode))
		{
			printf("%*s", -cfg->colWidth, cfg->colName);
		}
	}
	printf("\n");
	for (int i = begFileIdx; i < argc && argv[i]; ++i)
	{
		printf("%*s", -20, argv[i]);
		for (int col = 0; col < sColSize; ++col)
		{
			const ColConfig *cfg = getColConfig(col);
			if (cfg && (cfg->colKey & gColMode))
			{
				(cfg->printFunc)(argv[i], cfg);
			}
		}
		printf("\n");
	}

	exit(0);
}

void printFileMode(const char *pathname, const ColConfig *cfg)
{
	struct stat s;
	if (lstat(pathname, &s) < 0)
	{
		printf("%*s", -cfg->colWidth, strerror(errno));
		return;
	}

	const char *openMode = "rwxrwxrwx";
	const char *closeMode = "---------";
	static const int s_constMode[] = {
		S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH
	};

	char fileMode[10] = {0};
	memset(fileMode, 0, sizeof(fileMode));
	for (int i = 0; i < 9; ++i)
	{
		if (s.st_mode & s_constMode[i])
		{
			fileMode[i] = openMode[i];
		}
		else
		{
			fileMode[i] = closeMode[i];
		}
	}

	printf("%*s", -cfg->colWidth, fileMode);
}
