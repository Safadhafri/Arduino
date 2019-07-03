#include <FiniteStateMachine.h> //https://playground.arduino.cc/Code/FiniteStateMachine/



//�Զ��巽��
void function_1(){}
void function_2(){}
void function_3(){}
void function_4(){}

/**
 * enterFunction ���ڴ�״̬������ʱִ�еķ���
 * updateFunction ��״̬ˢ��ʱ���ô��ڶ�Ӧ�Ĵ�״̬�»�ִ�еķ���
 * exitFunction ��ȡ����״̬��ִ�еķ���
 */

//��״̬��������״̬��ע�⣬������������ʵ�ǽ�������Ӧ��ָ����Ϊ���������ڵ���ʱ�ɼӿɲ��ӡ�&�������������Լ��ж�
//��֪��Ϊʲô�������ǿ⺯����Դ���д�趨���⣬�����ﲻ�ü�&������protothread����Ҫ�ӣ�-
//�������ܲ��ܼ��ϴ���
//State ethernetDebugState = State( enterFunction , updateFunction , exitFunction );
State state_one = State(function_1);
State state_two = State(function_2);
State state_three = State(function_3);
State state_four = State(function_4);




//����״̬����state_XXX�ǳ�ʼ״̬
FSM stateMachine = FSM(state_one);


void setup(){
    
}

void loop(){
    //ˢ��״̬��
    stateMachine.update();

    //׼���ı�״̬���ı����֮�������ĵ�һ��ˢ��ʱ����
    stateMachine.transitionTo(State);

    //����ת��״̬
    stateMachine.immediateTransitionTo(State);

    //���ص�ǰ״̬
    stateMachine.getCurrentState();

    //���ص�ǰ״̬������һ����;ͬ��
    stateMachine.State();

    //�жϵ�ǰ״̬���Ƿ��������е�State״̬
    stateMachine.isInState(State);
}
