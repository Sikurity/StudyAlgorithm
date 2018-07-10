/**
*	@link	https://www.acmicpc.net/problem/9367
*	@date	2018. 07. 10
*	@author	Sikurity
*	@method Trie To Get Object By String
*/

#include <cstdio>
#include <cstring>

const int MAX_N = 500;		// 최대 차량/첩보원 수
const int MAX_M = 10000;	// 최대 사건 기록 로그 수

const int MAX_STR_LEN = 40;	// 최대 차량/첩보원 이름 길이
const int ALPHABET_NUM = 26;

template <typename T>
inline void SWAP(T &a, T &b) {
	T t = a;
	a = b;
	b = t;
}

template <typename T>
inline int partition(T list[], int l, int r) {
	int m = (l + r) >> 1;

	if (list[r] < list[l])
		SWAP(list[r], list[l]);

	if (list[m] < list[l])
		SWAP(list[m], list[l]);

	if (list[r] < list[m])
		SWAP(list[r], list[m]);

	T pivot = list[m];
	int low = l - 1;
	int high = r + 1;

	while (true) {
		while (list[++low] < pivot);
		while (pivot < list[--high]);

		if (high <= low)
			break;

		SWAP(list[low], list[high]);
	}

	return high;
}

template <typename T>
void quicksort(T list[], int l, int r) {
	if (l < r) {
		int p = partition(list, l, r);
		quicksort(list, l, p);
		quicksort(list, p + 1, r);
	}
}

struct TrieInfo {
	int testcase[ALPHABET_NUM];
	int nextNode[ALPHABET_NUM];
	int linked;
};

struct Car {
	char	name[MAX_STR_LEN + 1];
	int		originCost;
	int		rentalCost;
	int		addtnlCost;	// additional cost
};

struct Agent {
	char	name[MAX_STR_LEN + 1];
	int		rentalCarNum;
	int		repairCost;
	int		billingCost;
	bool	isConsistent;	// true = 일관, false = 비일관

	bool operator<(const Agent &a) const {
		return strcmp(name, a.name) < 0;
	}
};

int T, N, M;

Car		cars[MAX_N];
Agent	agents[MAX_N];

int CAR_TRIESIZE;
TrieInfo CAR_TRIE[MAX_N * MAX_STR_LEN * 2];

int AGENT_TRIESIZE;
TrieInfo AGENT_TRIE[MAX_N * MAX_STR_LEN * 2];

void init() {
	CAR_TRIESIZE = AGENT_TRIESIZE = 0;
}

bool check(int agentIdx, int carIdx, char evt) {

	switch (evt) {
	case 'p':
		// p. 대여중인 상태에서, 한 번 더 대여를 시도하는지 확인
		if (carIdx < 0 || agentIdx < 0 || agents[agentIdx].rentalCarNum != -1)
			return false;

		break;
	case 'r':
	case 'a':
		// r. 반납할 때, 대여를 한 건 맞는지 확인
		// a. 차를 대여중인 상태가 아니인데, 사고가 발생한 경우
		if (carIdx < 0 || agentIdx < 0 || agents[agentIdx].rentalCarNum == -1)
			return false;

		break;
	default:
		if (agentIdx < 0 || agents[agentIdx].rentalCarNum != -1)
			return false;

		// default. 마지막에 자신이 대여한 차를 반납했는지 확인
	}

	return true;
}

void inputCarInfo(int testcase) {
	char name[MAX_STR_LEN + 1];		// 차량명
	int p;	// 원가
	int q;	// 초기 대여 비용
	int k;	// 1km 당 추가비용

	int carNum = 0;
	for (int i = 0; i < N; i++) {
		scanf("%s", name);
		scanf("%d %d %d", &p, &q, &k);

		int node = 0;
		char *str = name;
		while (*str) {
			int next = *str - 'a';
			if (CAR_TRIE[node].testcase[next] < testcase) {
				CAR_TRIE[node].testcase[next] = testcase;
				CAR_TRIE[node].nextNode[next] = ++CAR_TRIESIZE;
				CAR_TRIE[CAR_TRIESIZE].linked = -1;
			}

			node = CAR_TRIE[node].nextNode[next];
			str++;
		}

		if (CAR_TRIE[node].linked == -1) {
			::strncpy(cars[carNum].name, name, ::strlen(name) + 1);
			cars[carNum].originCost = p;
			cars[carNum].rentalCost = q;
			cars[carNum].addtnlCost = k;

			CAR_TRIE[node].linked = carNum++;
		}
	}
}

int getCar(char *carName, int testcase) {
	int node = 0;
	char *s = carName;
	while (*s) {
		int next = *s - 'a';
		if (CAR_TRIE[node].testcase[next] < testcase)
			return -1;

		node = CAR_TRIE[node].nextNode[next];
		s++;
	}

	return CAR_TRIE[node].linked;
}

int inputAgentInfo(int testcase) {
	int t;	// 원가
	char name[MAX_STR_LEN + 1];	// 요원명
	char e[2];	// 사건종류
				// 'p': -carName(차량명), 차 대여
				// 'r': -d(주행거리), 반환
				// 'a': -s(파손율), 사고 발생
	int d;	// 주행거리
	int s;	// 파손율

	char carName[MAX_STR_LEN + 1];
	int carIdx;

	int agentNum = 0;
	for (int i = 0; i < M; i++) {
		scanf("%d %s %s", &t, name, e);

		int node = 0;
		char *str = name;
		while (*str) {
			int next = *str - 'a';
			if (AGENT_TRIE[node].testcase[next] < testcase) {
				AGENT_TRIE[node].testcase[next] = testcase;
				AGENT_TRIE[node].nextNode[next] = ++AGENT_TRIESIZE;
				AGENT_TRIE[AGENT_TRIESIZE].linked = -1;
			}

			node = AGENT_TRIE[node].nextNode[next];
			str++;
		}

		if (AGENT_TRIE[node].linked == -1) {
			::strncpy(agents[agentNum].name, name, ::strlen(name) + 1);
			agents[agentNum].rentalCarNum = -1;
			agents[agentNum].billingCost = 0;
			agents[agentNum].isConsistent = true;

			AGENT_TRIE[node].linked = agentNum++;
		}

		int idx = AGENT_TRIE[node].linked;
		if (agents[idx].isConsistent == false) {
			switch (e[0]) {
			case 'p':
				scanf("%s", carName);
				break;
			case 'r':
				scanf("%d", &d);
				break;
			case 'a':
				scanf("%d", &s);
				break;
			}
			continue;
		}

		switch (e[0]) {
		case 'p':	// 대여
			scanf("%s", carName);
			carIdx = getCar(carName, testcase);

			if (check(idx, carIdx, e[0])) {
				agents[idx].rentalCarNum = carIdx;
				agents[idx].billingCost += cars[carIdx].rentalCost;
			}
			else
				agents[idx].isConsistent = false;

			break;
		case 'r':	// 반환
			scanf("%d", &d);
			carIdx = agents[idx].rentalCarNum;

			if (check(idx, carIdx, e[0])) {
				agents[idx].billingCost += cars[carIdx].addtnlCost * d;
				agents[idx].rentalCarNum = -1;
			}
			else
				agents[idx].isConsistent = false;

			break;
		case 'a':	// 사고
			scanf("%d", &s);
			carIdx = agents[idx].rentalCarNum;

			if (check(idx, carIdx, e[0])) {
				int repairCost = cars[carIdx].originCost * s;
				repairCost = (repairCost / 100) + (repairCost % 100 ? 1 : 0);
				agents[idx].billingCost += repairCost;
			}
			else
				agents[idx].isConsistent = false;

			break;
		}
	}

	return agentNum;
}

int main() {

	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		init();

		scanf("%d %d", &N, &M);

		inputCarInfo(t);
		int agentNum = inputAgentInfo(t);

		quicksort(agents, 0, agentNum - 1); // 알파벳 순으로 정렬

		for (int i = 0; i < agentNum; i++) {
			if (agents[i].isConsistent && check(i, -1, NULL))
				printf("%s %d\n", agents[i].name, agents[i].billingCost);
			else
				printf("%s INCONSISTENT\n", agents[i].name);
		}
	}

	return 0;
}