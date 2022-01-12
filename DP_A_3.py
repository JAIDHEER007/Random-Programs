try:
    import sys
    import requests
    import json
except ModuleNotFoundError as mnfe:
    print(mnfe.msg)
    sys.exit("Please install the required packages using PIP")

url = 'https://leetcode.com/graphql'

headers = {'Accept-Language':'en-GB,en-US;q=0.9,en;q=0.8',
           'Connection':'keep-alive',
           'content-type':'application/json', 
           'Host':'leetcode.com', 
	       'user-agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/95.0.4621.4 Safari/537.36'}

payload = {"query":"""query problemsetQuestionList($categorySlug: String, $limit: Int, $skip: Int, $filters: QuestionListFilterInput) {
                problemsetQuestionList: questionList(
                    categorySlug: $categorySlug
                    limit: $limit
                    skip: $skip
                    filters: $filters) 
                {
                    questions: data {
                        title
                        titleSlug
                    }
                }
            }
	    """,
        "variables":{
            "categorySlug":"",
            "skip":53,
            "limit":1,
            "filters":{}
        }
}

qnum = (53 if len(sys.argv) == 1 else int(sys.argv[1]))
payload['variables']['skip'] = (qnum - 1)

qreq = requests.post(url = url, headers = headers, json = payload)
qdata = json.loads(qreq.text)

githubFolderLink = input('Enter github folder link: ')
qdone = input('Is the question completed: ')
remarks = input('Enter any remarks: ')

tableRow = "|{qnum}|{qtitle}|<a href='https://leetcode.com/problems/{qtitleSlug}/'>Link</a>|<a href='{githubLink}'>Link</a>|{isDone}|{remarks}|"

finalTR = tableRow.format(qnum = qnum, 
                          qtitle = qdata['data']['problemsetQuestionList']['questions'][0]['title'], 
                          qtitleSlug = qdata['data']['problemsetQuestionList']['questions'][0]['titleSlug'], 
                          githubLink = githubFolderLink, 
                          isDone = qdone, 
                          remarks = remarks)

print(finalTR)

try:
    import clipboard
    if input('Copy to clipboard (Y/N): ')[0] in 'yY': 
        clipboard.copy(finalTR)
except ModuleNotFoundError as mnfe:
    print(mnfe.msg)
    sys.exit("Please install the required packages using PIP")

return 0
