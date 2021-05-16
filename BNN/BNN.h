#pragma once
typedef struct protocolIO
{
	//user input
	float input[28][28];				//从文件输入
	float answer;						//从文件输入

	//model params
	//BinarizeConv2d(0)
	float BConv1_weight[6][5][5];		//从1_layer1_0_weight.txt输入
	float BConv1_bias[6];				//从2_layer1_0_bias.txt输入
	//BatchNorm2d(1)
	float BN1_weight[6];				//从3_layer1_1_weight.txt输入
	float BN1_bias[6];					//从4_layer1_1_bias.txt输入
	//BinarizeConv2d(4)
	float BConv2_weight[96][5][5];		//从8_layer2_0_weight.txt输入
	float BConv2_bias[16];				//从9_layer2_0_bias.txt输入
	//BatchNorm2d(5)
	float BN2_weight[16];				//从10_layer2_1_weight.txt输入
	float BN2_bias[16];					//从11_layer2_1_bias.txt输入
	
	//BinarizeLinear(0)
	float BL_weight[120][400];			//从15_fc1_weight.txt输入
	float BL_bias[120];					//从16_fc1_bias.txt输入
	//Linear(1)
	float Linear1_weight[84][120];		//从17_fc2_weight.txt输入
	float Linear1_bias[84];				//从18_fc2_bias.txt输入
	//Linear(2)
	float Linear2_weight[10][84];		//从19_fc3_weight.txt输入
	float Linear2_bias[10];				//从20_fc3_bias.txt输入

	//output
	int result;
	long start_s;
	long start_us;
	long end_s;
	long end_us;
	long timeuse_s;
	long timeuse_us;
	float Check[6][28][28];

} protocolIO;

void nn(void* args);
