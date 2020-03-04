#include "../Include/calci.h"

void arithmatic(struct request *req, struct response *resp)
{

	if (req->operat == '*')
	{
		resp->result = req->operan1 * req->operan2;
		resp->flag = 0;
		return;
	}

	if (req->operat == '/')
	{
		resp->result = req->operan1 / req->operan2;
		resp->flag = 0;
		return;
	}

	if (req->operat == '+')
	{
		resp->result = req->operan1 + req->operan2;
		resp->flag = 0;
		return;
	}

	if (req->operat == '-')
	{
		resp->result = req->operan1 - req->operan2;
		resp->flag = 0;
		return;
	}

	resp->flag = -1;
}

