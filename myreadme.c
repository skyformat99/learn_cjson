/*************************************************************************
  > File Name: mytest.c
  > Author: Sues
  > Mail: sumory.kaka@foxmail.com 
  > Created Time: Thu 26 Apr 2018 10:41:53 AM CST
 ************************************************************************/

#include <stdio.h>



//            --------> json 结构体
///////////////////////////////////////////////////
//
//
//                      1
//
//
//由已知json字符串获取 json 结构体
char text[]="{\n\"name\": \"Jack (\\\"Bee\\\") Nimble\", \n\"format\": {\"type\":       \"rect\", \n\"width\":      1920, \n\"height\":     1080, \n\"interlace\":  false,\"frame rate\": 24\n}\n}";	
cJSON * json=cJSON_Parse(text);


//
//
//                      2
//
//
//由已知片段 组合  获取 json结构体
cJSON * root=cJSON_CreateObject();	
cJSON_AddItemToObject(root, "name", cJSON_CreateString("Jack (\"Bee\") Nimble"));
cJSON_AddItemToObject(root, "format", fmt=cJSON_CreateObject());
cJSON_AddStringToObject(fmt,"type",		"rect");
cJSON_AddNumberToObject(fmt,"width",		1920);
cJSON_AddNumberToObject(fmt,"height",		1080);
cJSON_AddFalseToObject (fmt,"interlace");
cJSON_AddNumberToObject(fmt,"frame rate",	24);


root=cJSON_CreateStringArray(strings,7);


root=cJSON_CreateArray();


root=cJSON_CreateObject();
cJSON_AddItemToObject(root, "Image", img=cJSON_CreateObject());
cJSON_AddNumberToObject(img,"Width",800);
cJSON_AddNumberToObject(img,"Height",600);
cJSON_AddStringToObject(img,"Title","View from 15th Floor");
cJSON_AddItemToObject(img, "Thumbnail", thm=cJSON_CreateObject());
cJSON_AddStringToObject(thm, "Url", "http:/*www.example.com/image/481989943");
cJSON_AddNumberToObject(thm,"Height",125);
cJSON_AddStringToObject(thm,"Width","100");
cJSON_AddItemToObject(img,"IDs", cJSON_CreateIntArray(ids,4));


root=cJSON_CreateArray();
for (i=0;i<2;i++)
{
    cJSON_AddItemToArray(root,fld=cJSON_CreateObject());
    cJSON_AddStringToObject(fld, "precision", fields[i].precision);
    cJSON_AddNumberToObject(fld, "Latitude", fields[i].lat);
    cJSON_AddNumberToObject(fld, "Longitude", fields[i].lon);
    cJSON_AddStringToObject(fld, "Address", fields[i].address);
    cJSON_AddStringToObject(fld, "City", fields[i].city);
    cJSON_AddStringToObject(fld, "State", fields[i].state);
    cJSON_AddStringToObject(fld, "Zip", fields[i].zip);
    cJSON_AddStringToObject(fld, "Country", fields[i].country);
}


/*
 *
 * 一个json结构体可以 是 数组,可以是下面的任一种,添加元素的时候,要根据不同 类别的规矩添加
 *

 cJSON *cJSON_CreateNull(void)					{cJSON *item=cJSON_New_Item();if(item)item->type=cJSON_NULL;return item;}
 cJSON *cJSON_CreateTrue(void)					{cJSON *item=cJSON_New_Item();if(item)item->type=cJSON_True;return item;}
 cJSON *cJSON_CreateFalse(void)					{cJSON *item=cJSON_New_Item();if(item)item->type=cJSON_False;return item;}
 cJSON *cJSON_CreateBool(int b)					{cJSON *item=cJSON_New_Item();if(item)item->type=b?cJSON_True:cJSON_False;return item;}
 cJSON *cJSON_CreateNumber(double num)			{cJSON *item=cJSON_New_Item();if(item){item->type=cJSON_Number;item->valuedouble=num;item->valueint=(int)num;}return item;}
 cJSON *cJSON_CreateString(const char *string)	{cJSON *item=cJSON_New_Item();if(item){item->type=cJSON_String;item->valuestring=cJSON_strdup(string);}return item;}
 cJSON *cJSON_CreateArray(void)					{cJSON *item=cJSON_New_Item();if(item)item->type=cJSON_Array;return item;}
 cJSON *cJSON_CreateObject(void)					{cJSON *item=cJSON_New_Item();if(item)item->type=cJSON_Object;return item;}

 Create Arrays:
 cJSON *cJSON_CreateIntArray(const int *numbers,int count)		{int i;cJSON *n=0,*p=0,*a=cJSON_CreateArray();for(i=0;a && i<count;i++){n=cJSON_CreateNumber(numbers[i]);if(!i)a->child=n;else suffix_object(p,n);p=n;}return a;}
 cJSON *cJSON_CreateFloatArray(const float *numbers,int count)	{int i;cJSON *n=0,*p=0,*a=cJSON_CreateArray();for(i=0;a && i<count;i++){n=cJSON_CreateNumber(numbers[i]);if(!i)a->child=n;else suffix_object(p,n);p=n;}return a;}
 cJSON *cJSON_CreateDoubleArray(const double *numbers,int count)	{int i;cJSON *n=0,*p=0,*a=cJSON_CreateArray();for(i=0;a && i<count;i++){n=cJSON_CreateNumber(numbers[i]);if(!i)a->child=n;else suffix_object(p,n);p=n;}return a;}
 cJSON *cJSON_CreateStringArray(const char **strings,int count)	{int i;cJSON *n=0,*p=0,*a=cJSON_CreateArray();for(i=0;a && i<count;i++){n=cJSON_CreateString(strings[i]);if(!i)a->child=n;else suffix_object(p,n);p=n;}return a;}

 * */

/*
 * 一般我们用 cJSON_CreateObject
 *                                  这下面可以挂 string int 任意类型json结构体 
 * 或者用 cJSON_CreateArray
 *                                  这里面第一个元素可以挂任何 东西,但是第二个元素必须要挂同等的东西
 *                                  在创建数组的时候并没有创建数组大小
 *
 * 或者用 cJSON_CreateStringArray
 *                                  这里面创建的时候已经 初始化完毕了.
 *
 * */





//            --------> json 内容
///////////////////////////////////////////////////
//
//
//                      3
//
//
//由已知 json 结构体 获取 字符串整体
char *out = cJSON_Print(json);printf("%s\n",out);free(out); //带回车
char *out = cJSON_PrintUnformatted(json);printf("%s\n",out);free(out); //不带回车



//
//
//                      4
//
//
//由已知 json 结构体 获取 局部信息

cJSON * json=cJSON_Parse(text);

//1
int SN = cJSON_GetObjectItem(root,"SN")->valueint; 
char SID[256] = {0};strcpy(SID,cJSON_GetObjectItem(root,"SID")->valuestring);
//2
cJSON * PL = cJSON_GetObjectItem(root,"PL");
int EID = cJSON_GetObjectItem(PL,"EID")->valueint;
//3
cJSON_GetArraySize(root);
cJSON_GetArrayItem(root,i)->valuestring);

