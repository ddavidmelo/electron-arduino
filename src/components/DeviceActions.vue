<template>
  <q-page class="flex flex-center">
    <q-list bordered padding class="rounded-borders" style="width: 350px">
      <q-item>
        <q-item-section avatar>
          <q-avatar icon="lightbulb" color="grey" text-color="white" />
        </q-item-section>
        <q-item-section>
          <q-toggle @update:model-value="(value) => sendCommand('LED_BUILTIN',value)" v-model="LED_BUILTIN" label="LED_BUILTIN" />
        </q-item-section>
      </q-item>

      <q-item>
        <q-item-section avatar>
          <q-avatar icon="lightbulb" color="grey" text-color="white" />
        </q-item-section>
        <q-item-section>
          <q-toggle @update:model-value="(value) => sendCommand('LED_PWR',value)" v-model="LED_PWR" label="LED_PWR" />
        </q-item-section>
      </q-item>

      <q-item>
        <q-item-section avatar>
          <q-avatar icon="lightbulb" color="red" text-color="white" />
        </q-item-section>
        <q-item-section>
          <q-toggle @update:model-value="(value) => sendCommand('LEDR',value)" v-model="LEDR" label="LEDR" />
        </q-item-section>
      </q-item>
      <q-item>
        <q-item-section avatar>
          <q-avatar icon="lightbulb" color="green" text-color="white" />
        </q-item-section>
        <q-item-section>
          <q-toggle @update:model-value="(value) => sendCommand('LEDG',value)" v-model="LEDG" label="LEDG" />
        </q-item-section>
      </q-item>
      <q-item>
        <q-item-section avatar>
          <q-avatar icon="lightbulb" color="blue" text-color="white" />
        </q-item-section>
        <q-item-section>
          <q-toggle @update:model-value="(value) => sendCommand('LEDB',value)" v-model="LEDB" label="LEDB" />
        </q-item-section>
      </q-item>


    </q-list>
  </q-page>
</template>

<style></style>

<script>
export default {
  data() {
    return {
      LEDR: false,
      LEDG: false,
      LEDB: false,
      LED_BUILTIN: false,
      LED_PWR: false,
    }
  },
  methods: {
    sendCommand(led,value){
      var command;
      if (value) {
        command = "AT+LED="+led+":1";
      } else {
        command = "AT+LED="+led+":0";
      }
      this.$emit("command", command);
    }
  }
}
</script>